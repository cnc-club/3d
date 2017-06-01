#-*- coding: utf8 -*-
import struct

def enum(**enums):
    return type('Enum', (), enums)

class OwenError(Exception):
    """Базовый класс для исклЮчений"""
    pass

class OwenProtocolError(OwenError):
    """ИсклЮчение вызвано ошибкой в протоколе (выход за границы дипазонов, отсутствие данных и др.)
    Attributes:        
        msg  -- текст ошибки
    """
    def __init__(self, msg):
        self.msg = msg
    def __str__(self):
       return repr(self.msg)

class OwenUnpackError(OwenError):
    """ИсклЮчение вызвано ошибкой распаковки данных
    Attributes:        
        msg  -- текст ошибки
        data -- данные
    """
    def __init__(self, msg, data):
        self.msg = msg
        self.data = data
    def __str__(self):
       return repr('{} Data: {}'.format(self.msg,list(self.data)))

class OwenNewtworkError(OwenError):
    """ИсклЮчение вызвано ошибкой получения, отправки данных
    Attributes:        
        msg  -- текст ошибки
    """
    def __init__(self, msg):
        self.msg = msg
    def __str__(self):
       return repr(self.msg)

class OwenCrcError(OwenError):
    """ИсклЮчение вызвано ошибкой в контрольной сумме
    Attributes:        
        msg  -- текст ошибки
        frame -- данные
    """
    def __init__(self, msg,frame):
        self.msg = msg
        self.frame = frame
    def __str__(self):
       return repr('{} Frame: {}'.format(self.msg,list(self.frame)))

class OwenProtocol:#Класс, реализующий протокол ОВЕН напрямую в пайтон
    def __init__(self,address = 16, addrLen = 8):
        self.data = '' #данные для передачи
        self.dataSize = 0 #количество полученных байтов
        self.address = 16 #адрес устройства
        self.addrLen = 8 #длина адреса, может быть 8 или 11 бит
        self.request = False #признак запроса
        self.hash = 0 #хэш параметра ОВЕН
        self.crc = 0 #контрольная сумма
        self.crcOk = True #контрольная сумма верна
        self.maxFrameSize = 21 #максимальная длина пакета согласно протоколу ОВЕН
        self.maxAsciiFrameSize = 44 #максимальная длина ASCII-пакета включая маркеры
        self.frame = '' #фрейм в бинарном виде
        self.frameAscii = '' #фрейм в строковом виде
        self.waitBytes = self.maxAsciiFrameSize # сколько байтов ждать от устройства        

    def __str__(self):
        return ('Address: {} Address length: {}\nHash: {} Request: {}\nData size: {} Data: {}\n'+\
                'Frame: {}\nFrame in ascii: {}\nCrc: {} Crc is OK: {}').format(self.address,self.addrLen,self.hash,self.request,self.dataSize,list(self.data),\
                                                         list(self.frame),self.frameAscii,self.crc,self.crcOk)

    def appendIndexAndTime(self,index = -1, time = -1):
        if not time == -1:
            self.data += chr((time >> 8) & 0x0f)
            self.data += chr(time & 0x0f)
        if not index == -1:
            self.data += chr((index >> 8) & 0x0f)
            self.data += chr(index & 0x0f)

    def CalcAnswerBytes(self,dataSize=-1):#считает количество байт, которые должны вернуться от устройства
        if dataSize == -1:        
            self.waitBytes = self.maxAsciiFrameSize
        else:
            self.waitBytes = 2 + 6*2 + 2*dataSize # 2 байта маркеры, 6*2 -- адрес, флаги, хэш и контрольная сумма
        return self.waitBytes

    def owenCRC16(self,packet):#считаем crc строки символов, packet - ansi строка
        i = j = 0
        crc = 0
        if packet == '':
            raise OwenProtocolError('OwenProtocol::empty packet!')
        for i in range(len(packet)):
            byte = ord(packet[i])    
            for j in range(1,9):                
                if (byte ^ (crc >> 8)) & 0x80:
                    crc <<= 1 
                    crc ^= 0x8F57
                else:
                    crc <<= 1 
                byte <<= 1
                byte &= 0xff    
                crc &= 0xffff                    
        return crc
        
    def packFrameToAscii(self):#преобразуем бинарные данные в строковый вид
        self.frameAscii=''
        if self.frame == '':
            raise OwenProtocolError('OwenProtocol::empty frame!')            
        self.frameAscii += '#'#стартовый символ
        for i in range(len(self.frame)):            
            self.frameAscii += chr(ord('G') + ((ord(self.frame[i]) >> 4) & 0x0f))#первая тетрада
            self.frameAscii += chr(ord('G') + (ord(self.frame[i]) & 0x0f))#вторая тетрада
        self.frameAscii += chr(13)
        
    #свертка локального идентификатора (преобразование из четырех-байтового представления в двух-байтовое)
    #id - строка из 4-х символов
    def id2hash(self,id):
        if id == '':
            raise OwenProtocolError('OwenProtocol::empty id!')        
        if len(id) < 4:
            raise OwenProtocolError('OwenProtocol::id length less than 4!')                    
        if len(id) > 4:
            raise OwenProtocolError('OwenProtocol::id length more than 4!')                                
        hash = 0
        for i in range(4):
            byte = ord(id[i])            
            byte <<= 1 #используются только младшие 7 бит
            byte &= 0xff
            for j in range(7):
                if (byte ^ (hash >> 8)) & 0x80 == 0x80:
                    hash <<= 1                
                    hash ^= 0x8F57
                else:
                    hash <<= 1;
                hash &= 0xffff
                byte <<= 1
                byte &= 0xff
        self.hash = hash
        return hash
    
    #преобразование локального идентификатора в двоичный вид
    #name - строка, содержащая имя локального идентификатора
    def name2id(self,name):
        if name == '':
            raise OwenProtocolError('OwenProtocol::empty name of parameter!')
        id = [0,0,0,0]
        j = 0
        for i in range(len(name)):
            char = name[i]
            byte = 0            
            if '0' <= char and char <= '9':
                byte = ord(char) - ord('0')
            elif ('a' <= char and char <= 'z'):
                byte = 10 + ord(char) - ord('a')
            elif ('A' <= char and char <= 'Z'):
                byte = 10 + ord(char) - ord('A')
            elif ('-' == char):
                byte = 10 + 26 + 0
            elif ('_' == char):
                byte = 10 + 26 + 1
            elif ('/' == char):
                byte = 10 + 26 + 2;
            elif ('.' == char):
                if i == 0:
                    #модификатор не может быть первым символом
                    raise OwenProtocolError('OwenProtocol::point at zero position in name {}!'.format(name))
                if i > 0 and name[i-1] == '.':
                    #не может быть двух модификаторов подряд
                    raise OwenProtocolError('OwenProtocol::two points are together in name {}!'.format(name))
                id[j-1] += 1
                continue
            elif (' ' == char):
                break #пробел может находиться только в конце имени
            else:
                #недопустимый символ
                raise OwenProtocolError('OwenProtocol::Illegal symbol in name {} !'.format(name))            
            id[j] = byte*2            
            j += 1
            if j == 4:
                if not (i<len(name)-1 and name[i+1] == '.'):#следуЮщий символ не точка
                    break #длина идентификатора не может быть больше 4-х
        if j == 4:
            #заполнены все байты идентификатора
            if i < (len(name)-1):#Если остались ещё символы выбрасываем исклЮчение
                raise OwenProtocolError('OwenProtocol::name {} is too long!'.format(name))
        else:
            #встречен первый пробел или обработаны все символы имени
            for i in range(i+1,len(name)):
                if not name[i] == ' ':#после пробела могут находиться только пробелы
                    raise OwenProtocolError('OwenProtocol::name {} is too long!'.format(name))
                if j >= 4:#после пробела могут находиться только пробелы
                    raise OwenProtocolError('OwenProtocol::name {} is too long!'.format(name))                
                id[j] = 78
                j += 1
            #дополняем пробелами до четырех символов
            for j in range(j,4):
                id[j] = 78
        #формируем результируЮщуЮ строку
        idStr=''                
        for i in range(4):
            #print '{0:#x}'.format(id[i])
            idStr += chr(id[i])
        return idStr

    def unpackAsciiFrame(self):#преобразует данные, полученные от устройства, в бинарный вид
        if self.frameAscii == '':
            raise OwenProtocolError('OwenProtocol::ascii buffer is empty!')
        frameAsciiSize=len(self.frameAscii)
        if not (self.frameAscii[0] == '#' and self.frameAscii[-1] == '\x0d'):            
            raise OwenProtocolError('OwenProtocol::ascii buffer does not have start or stop bytes! Frame ascii: {}'.format(list(self.frameAscii)))
        if not ((frameAsciiSize & 1) == 0):
            raise OwenProtocolError('OwenProtocol::ascii buffer has not even length! Frame ascii: {}'.format(list(self.frameAscii)))
        i = j = 0
        self.frame = ''
        for i in range(1,frameAsciiSize-2,2):
            #склеиваем тетрады
            byteFirst=self.frameAscii[i]
            byteSecond=self.frameAscii[i+1]
            if not ('G' <= byteFirst and byteFirst <= 'V'):
                raise OwenProtocolError('OwenProtocol::wrong symbol in ascii buffer!')
            if not ('G' <= byteSecond and byteSecond <= 'V'):
                raise OwenProtocolError('OwenProtocol::wrong symbol in ascii buffer!')
            byte = (ord(self.frameAscii[i]) - ord('G')) << 4 | (ord(self.frameAscii[i+1]) - ord('G'))
            self.frame += chr(byte)
        return self.frame

    def packIEEE32(self,value):#упаковываем число с плавающей точкой для передачи на устройство
        self.data = struct.pack('>f',value)
        return self.data
    
    def packInt16(self,value):#упаковываем целое число для передачи на устройство
        self.data = struct.pack('>H',value)

    def packString(self,value):        
        self.data = value[::-1]

    def packChar(self,value): #пакует байт
        self.data = struct.pack('b',value)

    def unpackIEEE32(self, withIndex = False, withTime = False):#извлекает из данных число с плаваЮщей точкой и время
        additionalBytes = 0
        if withTime:
            timePos = 4 
            additionalBytes += 2
        if withIndex:
            indexPos = 4 + additionalBytes 
            additionalBytes += 2                        
        if not (self.dataSize == 4 + additionalBytes):
            raise OwenUnpackError('OwenProtocol::wrong size of data ({0}) when IEEE32 unpacking, should be {1}!'.format(self.dataSize,(4 + additionalBytes)),\
                                  self.data)
        value = struct.unpack('>f',self.data[0:4])[0]
        if withTime:
            time = (((ord(self.data[timePos]) & 0xff) << 8) | (ord(self.data[timePos+1]) & 0xff )) & 0xffff
        else:
            time = -1
        if withIndex:
            index = (((ord(self.data[indexPos]) & 0xff) << 8) | (ord(self.data[indexPos+1]) & 0xff )) & 0xffff
        else:
            index = -1
        result = dict(value = value, time = time, index = index)
        return result
    
    def unpackFloat24(self, withIndex = False, withTime = False):#извлекает из данных число с плаваЮщей точкой
        if not (self.dataSize == 3):
            raise OwenUnpackError('OwenProtocol::wrong size of data ({0}) when float24 unpacking!'.format(self.dataSize),self.data)            
        value = struct.unpack('>f',self.data[0:3]+'\x00')[0]
        result = dict(value = value, time = -1, index = -1)
        return result

    def unpackInt16(self, withIndex = False, withTime = False):#извлекает из данных целое число со знаком
        if not (self.dataSize >= 1):
            raise OwenUnpackError('OwenProtocol::wrong size of data ({}) when unsigned short unpacking!'.format(self.dataSize),self.data)
        if self.dataSize == 1: 
            self.data = '\x00' + self.data  # дополняем до двух байтов
        #value = ord(self.data[1]) + (ord(self.data[0])<<8 & 0xffff);        
        value = struct.unpack('>h',self.data[0:2])[0]
        result = dict(value = value, time = -1, index = -1)
        return result

    def unpackUnsignedInt16(self, withIndex = False, withTime = False):#извлекает из данных целое число со знаком
        if not (self.dataSize >= 1):
            raise OwenUnpackError('OwenProtocol::wrong size of data ({}) when unsigned short unpacking!'.format(self.dataSize),self.data)
        if self.dataSize == 1: 
            self.data += '\x00' # дополняем до двух байтов
        #value = ord(self.data[1]) + (ord(self.data[0])<<8 & 0xffff);        
        value = struct.unpack('>H',self.data[0:2])[0]
        result = dict(value = value, time = -1, index = -1)
        return result


    def unpackString(self,withIndex = False, withTime = False): # распаковываем строку       
        #value = struct.unpack('>{0}s'.format(len(self.data)),self.data)[0] #почему-то не инвертирует порядок байтов
        value = self.data[::-1] # обратный порядок
        result = dict(value = value, time = -1, index = -1)
        return result
        
    def unpackChar(self):#извлекает из данных байт со знаком, возвращает целый тип
        if not (self.dataSize == 1):
            raise OwenUnpackError('OwenProtocol::wrong size of data ({0}) when char unpacking!'.format(self.dataSize),self.data)            
        value = struct.unpack('b',self.data[0])[0]
        result = dict(value = value, time = -1, index = -1)
        return result

    def unpackUnsignedChar(self):#извлекает из данных байт без знака, возвращает целый тип
        if not (self.dataSize == 1):
            raise OwenUnpackError('OwenProtocol::wrong size of data ({0}) when char unpacking!'.format(self.dataSize),self.data)            
        value = struct.unpack('B',self.data[0])[0]
        result = dict(value = value, time = -1, index = -1)
        return result
    
    def unpackFrame(self): # расшифровка пакета, проверка контрольной суммы
        frame = self.frame
        if frame == '':
            raise OwenProtocolError('OwenProtocol::frame is empty!')        
        if len(frame) < 6:
            raise OwenProtocolError('OwenProtocol::small length of frame!')        
        #/* ВНИМАНИЕ: невозможно отличить 11-битые адреса кратные 8 от 8-битных */
        if ord(frame[1]) & 0xe0 == 0xe0:
            address = ((ord(frame[0]) << 3) & 0xff) | ((ord(frame[1]) >> 5) & 0xff)
            addrLen = 11
        else:
            address = ord(frame[0])
            addrLen = 8
        if not (address == self.address and addrLen == self.addrLen):
            #raise OwenProtocolError('OwenProtocol::address and(or) address length are(is) different!')
            pass
        #запрос
        self.request = not ((ord(frame[1]) & 0x10) == 0)
        #хэш
        self.hash = ((ord(frame[2] )<< 8) & 0xff) | ord(frame[3])
        #размер данных
        dataSize = ord(frame[1]) & 0x0F
        if dataSize > 0:
            if not (dataSize == len(frame) - 6):
                raise OwenProtocolError('OwenProtocol::wrong data size value in frame!')        
            self.dataSize = dataSize
            #данные
            self.data = frame[4:4+dataSize]
        else:
            self.dataSize = 0
            self.data = ''
        #контрольная сумма
        self.crc = ((ord(frame[-2]) << 8) & 0xffff) | ord(frame[-1])
        self.crcOk = self.crc == self.owenCRC16(frame[:-2])
        if not self.crcOk:
            raise OwenCrcError('OwenProtocol::CRC mismatch!',self.frame)

    def packFrame(self,needDataSize = -1):#формирует массив байтов из данных класса для передачи на устройство, возвращает фрейм в виде строки
        frame = []
        #адрес
        if self.addrLen == 8:
            frame.append(self.address & 0xff)
            frame.append(0)
        else:
            frame.append((self.address >> 3)  & 0xff)
            frame.append((self.address & 0x07) << 5)            
        #признак запроса    
        if self.request:
            frame[1] |= 0x10
        #размер данных
        self.dataSize = len(self.data)    
        if self.dataSize > self.maxFrameSize-6:
            raise OwenProtocolError('OwenProtocol::data size is more then {}'.format(self.maxFrameSize-6))            
        frame[1] |= self.dataSize;
        #хэш
        frame.append((self.hash >> 8) & 0xff)
        frame.append(self.hash & 0xff);
        #данные
        if self.dataSize > 0:
            for i in range(len(self.data)):
                frame.append(ord(self.data[i]))
        #преобразуем массив в строку
        frameStr = ''
        for i in range(len(frame)):
            frameStr += chr(frame[i])
        #считаем контрольнуЮ сумму
        crc = self.owenCRC16(frameStr);
        self.crc = crc;
        self.crcOk = True;
        #добавляем контрольнуЮ сумму к посылке
        frameStr += chr((crc >> 8) & 0xff)
        frameStr += chr(crc & 0xff)
        if len(frameStr) > self.maxFrameSize:
            raise OwenProtocolError('OwenProtocol::frame size is more then {}'.format(self.maxFrameSize))
        self.frame = frameStr
        self.CalcAnswerBytes(needDataSize) #считаем сколько данных должно вернуться, для ускорения обмена
        return frameStr;

class NetworProtocolSettings:
    def __init__(self, baudRateI = 0, lenI = 0, parityI = 0, stopBitsI = 0, address = 0, addressLengthI = 0, errorNumber=0,answerDelay=0):
        self.__baudRates = [2400,4800,9600,14400,19200,28800,38400,57600,115200]
        self.__BitLengthes = [7,8]
        self.__Parities = ['No','EuEn','Odd']
        self.__StopBits = [1,2]
        self.__AddrLens = [8,11]
        
        self.baudRate = self.__baudRates[baudRateI] #Скорость обмена (бод)
        self.bits = self.__BitLengthes[lenI] # Длина слова данных (бит)
        self.parity = self.__Parities[parityI] # Состояние бита четности в посылке
        self.baseAddress = address # Базовый адрес прибора
        self.stopBits = self.__StopBits[stopBitsI] # Количество стоп-битов в посылке
        self.addressLength = self.__AddrLens[addressLengthI] # Длина сетевого адреса  (бит)
        self.errorNumber = errorNumber # Код сетевой ошибки при последнем обращении к прибору.
        self.answerDelay = answerDelay # Задержка ответа от прибора по RS485 (мс)
    def __str__(self):
        return ('Baud rate: {} Bit length: {} Parity: {} Stop bits: {}\n'+\
               'Base address: {} Address length: {} Aswer delay: {} Last error: {}').format(self.baudRate,self.bits,self.parity,self.stopBits,\
                                                                                           self.baseAddress,self.addressLength,self.answerDelay,self.errorNumber)
               
        
class OwenDevice:
    #Конструктор
    #serialPort - объект, поддерживающий чтение и запись в последовательный порт, можно использовать стандартный Serial из пакета pySerial
    # address - базовый адрес устройства
    def __init__(self,serialPort=None,address=16,addrLen=8):
        self.serialPort = serialPort#класс последовательного порта
        self.baseAddress = address
        self.owenProtocol = OwenProtocol(address,addrLen)
        self.Debug = False #режим вывода отладочных сообщений
        self.hashCash = dict() # кэш хэшей
        self.__TestResponseStringForIEEE32 = "#HOGMONOKSIKNVVQNGVUHTRGK"+chr(13)#эта строка будет "читаться" из устройства, если serialPort=None
        self.__TestResponseStringForStringType = "#HGGMTMOHJHJLJIKTLGLKVUMM"+chr(13)#эта строка будет "читаться" из устройства, если serialPort=None
        self.__TestResponseString = self.__TestResponseStringForStringType
        
     
    def DebugMessage(self,message):#вывод отладочных сообщений
        if self.Debug:
            print message
            
    def GetDeviceName(self):#возвращает имя устройства
        return self.GetString('dev')

    def GetFirmwareVersion(self):#возвращает версию прошивки
        return self.GetString('ver')

    def GetNetworkSettings(self):
        baudRate = self.GetChar('bps')
        Len = self.GetChar('Len')
        PrtY = self.GetChar('PrtY')
        aLen = self.GetChar('a.len')        
        if aLen == 0:
            Addr = self.GetChar('Addr')
        else:
            Addr = self.GetInt16('Addr')
        sBits = self.GetChar('sbit')        
        nErr = self.GetChar('n.Err')
        rsDelay = self.GetChar('rS.dL')
        return NetworProtocolSettings(baudRate,Len,PrtY,sBits,Addr,aLen,nErr,rsDelay)

    def GetHash(self,name): # считаем хэш по имени параметра
        name = name.upper()
        if self.hashCash.has_key(name):
            return self.hashCash[name]
        else:
            id = self.owenProtocol.name2id(name)
            hash = self.owenProtocol.id2hash(id)
            self.hashCash[name] = hash
        return hash
        
    def PackFrame2Ascii(self,hash,request=True): # формируем строку из фрейма для отправки на устройство
        self.owenProtocol.hash=hash		
        self.owenProtocol.request=request
        frameSize = len(self.owenProtocol.packFrame())
        self.DebugMessage('Sending::frame size: {0}  addr: {1:#x} hash: {2:#x}'.format(frameSize,self.owenProtocol.address,self.owenProtocol.hash))
        if len(self.owenProtocol.data) > 0:
            self.DebugMessage('Sending::data: {}'.format(list(self.owenProtocol.data)))
        self.owenProtocol.packFrameToAscii()
        return self.owenProtocol.frameAscii
        
    def WriteToPort(self):#отправляем данные устройству
        self.DebugMessage( 'Sent: {}'.format(self.owenProtocol.frameAscii))            
        if self.serialPort!=None: 
            self.serialPort.write(self.owenProtocol.frameAscii)
        return True
        
    def ReadFromPort(self):#чтение ответа из порта
        self.owenProtocol.frameAscii=''
        if self.serialPort!=None: 
            (flag,charsFromPort)=self.serialPort.read(self.owenProtocol.waitBytes)
            if not flag:
                raise OwenProtocolError('OwenDevice::Error occured when recieving data from serial port!')
            if charsFromPort=='':
                raise OwenProtocolError('OwenDevice::No data are recieved from serial port!')
            self.owenProtocol.frameAscii=charsFromPort                
        else:
            self.owenProtocol.frameAscii= self.TestResponseString#возвращаем эту строку если порт не определён
        return self.owenProtocol.frameAscii

    def TakeHashFrom(self,hashOrName):
        if type(hashOrName) == str:
            hash = self.GetHash(hashOrName)
        else:
            hash = hashOrName
        return hash
        
    def GetPingPong(self,hash,addrOffset=0,answerDataSize = -1): #отправка фрейма запроса , получение ответа, addrOffset - смещение относительно базового адреса, answerDataSize - сколько байт данных ждем от устройства
        self.owenProtocol.address=self.baseAddress+addrOffset
        self.owenProtocol.data = ''        
        self.PackFrame2Ascii(hash,True)
        self.WriteToPort()
        self.owenProtocol.CalcAnswerBytes(answerDataSize)
        self.ReadFromPort()
        frameAsciiRecvSize=len(self.owenProtocol.frameAscii)
        self.DebugMessage( 'Reading::Length: {1} Recieved: {0}'.format(self.owenProtocol.frameAscii,frameAsciiRecvSize))                    
        if frameAsciiRecvSize>0:
            self.owenProtocol.unpackAsciiFrame();
            self.owenProtocol.unpackFrame();
            self.DebugMessage('Reading::data size: {0}'.format(self.owenProtocol.dataSize))
            self.DebugMessage('Reading::data: {0}'.format(list(self.owenProtocol.data)))
            #ошибки
            if answerDataSize>0 and not self.owenProtocol.dataSize == answerDataSize: 
                return False # не совпало количество принятых данных с желаемой длиной
        else:
            raise OwenNewtworkError('OwenDevice::no answer from device when reading data!')
        return True
        
    def GetInt16(self,hashOrName,addrOffset = 0, withTime = False, withIndex = False):#возвращает целочисленный параметр по хэшу или имени, addrOffset - смещение относительно базового адреса
        hash = self.TakeHashFrom(hashOrName)
        if self.serialPort == None:
            self.TestResponseString = self.__TestResponseStringForIEEE32        
        if self.GetPingPong(hash,addrOffset):
            if withTime or withIndex:
                return self.owenProtocol.unpackInt16()
            else:
                return self.owenProtocol.unpackInt16()['value']
        else:
            raise OwenProtocolError('OwenDevice::data size mismatch!')

    def GetChar(self,hashOrName,addrOffset=0, withTime = False, withIndex = False):#возвращает байт со знаком параметр по хэшу или имени,, addrOffset - смещение относительно базового адреса
        hash = self.TakeHashFrom(hashOrName)
        if self.serialPort == None:
            self.TestResponseString = self.__TestResponseStringForIEEE32        
        if self.GetPingPong(hash,addrOffset,1):
            if withTime or withIndex:
                return self.owenProtocol.unpackChar()
            else:
                return self.owenProtocol.unpackChar()['value']
        else:
            raise OwenProtocolError('OwenDevice::data size mismatch!')  
                        
    def GetIEEE32(self, hashOrName, addrOffset = 0, withTime = False, withIndex = False):#возвращает параметр float32 и время по хэшу  или имени,, addrOffset - смещение относительно базового адреса
        hash = self.TakeHashFrom(hashOrName)        
        if self.serialPort == None:
            self.TestResponseString = self.__TestResponseStringForIEEE32          
        answerLength = 4        
        if withTime:
            answerLength += 2
        if withIndex:
            answerLength += 2            
        result = self.GetPingPong(hash,addrOffset,answerLength) # для скорости задаём число принимаемых байтов
        #result = self.GetPingPong(hash,addrOffset)        
        if withTime or withIndex:
            return self.owenProtocol.unpackIEEE32(withIndex,withTime)
        else:
            return self.owenProtocol.unpackIEEE32(withIndex,withTime)['value']
                
        
    def GetString(self,hashOrName,addrOffset=0, withTime = False, withIndex = False):#возвращает строку по хэшу или имени,, addrOffset - смещение относительно базового адреса
        hash = self.TakeHashFrom(hashOrName)
        if self.serialPort == None:
            self.TestResponseString = self.__TestResponseStringForStringType        
        if self.GetPingPong(hash,addrOffset):
            if withTime or withIndex:
                return self.owenProtocol.unpackString()
            else:
                return self.owenProtocol.unpackString()['value']
        else:
            raise OwenProtocolError('Owen::no answer from device!')                
            
def test(): 
    print 'Test of owen class started...'        
    #тестовый  режим 
    #для работы с реальным ком-портом нужны библиотеки pyWin32 и pySerial
    owen=OwenDevice(None,16)#создаем устройство без указания порта, это значит, что вместо данных будет приходить тестовая строка
    owen.Debug=True#включаем вывод отладочных сообщений
    result=owen.GetDeviceName()#получаем название устройства, в тестовом режиме будет TPM251
    print 'Device name: {}'.format(result)    
    result=owen.GetFirmwareVersion()#получаем версию устройства, в тестовом режиме будет TPM251
    print 'Firmware version: {}'.format(result)        
    #рассчитываем хэши
    hashDEV=owen.GetHash('dev')
    hashROUT=owen.GetHash('r.oUt')
    hashRST=owen.GetHash('r.St')
    hashREAD=owen.GetHash('rEAd')
    print 'Hashes:'
    print 'Hash rEAd: {0:#x} Hash r.oUt: {1:#x} Hash r.St: {2:#x}'.format(hashREAD,hashROUT,hashRST) 
    #получение и разбор ответа от устройства в формате с плавающей точкой(в тестовом режиме возвращается значение (-49.99966049194336, 4065))
    result=owen.GetIEEE32(hashROUT, withTime = True)
    result=owen.GetIEEE32('r.oUt', withTime = True)#тоже самое
    print 'Response from device IEEE32: ',result
    #получение и разбор ответа от устройства в целочисленном формате(в тестовом режиме возвращается значение 49735)
    result=owen.GetInt16(hashROUT)
    result=owen.GetInt16('r.oUt')#тоже самое
    print 'Response from device Int: ',result
    #получение и разбор ответа от устройства в строковом формате(в тестовом режиме возвращается значение TPM251)
    result=owen.GetString(hashDEV)
    result=owen.GetString('dev')#тоже самое
    print 'Response from device String:', result
    print 'Owen protocol state:'
    print owen.owenProtocol
    print 'Test of owen class completed!\n'            