# -*- coding: utf8 -*-

from TOwen import Owen
from TSystem import MySerial

Owen.test()#прогоняем тест библиотеки

#создаем последовательный порт
try:
    #COM = MySerial.ComPort(11, 9600, timeout=1)#открываем COM12 (нумерация портов начинается с 0)
    COM = MySerial.ComPort(0, 9600, timeout=1)#открываем COM1 (нумерация портов начинается с 0)
except:
    raise Exception('Error openning port!')

COM.LoggingIsOn=True#включаем логирование в файл

#создаем устройство
#owenDev=Owen.Owen(None,16);#тестовые данные
owenDev=Owen.OwenDevice(COM,16);#настоящий порт

owenDev.Debug=True#включем отладочные сообщения

#Имя устройства
devName = owenDev.GetDeviceName()
print 'Device name: {}'.format(devName)
#Прошивка
result = owenDev.GetFirmwareVersion()
print 'Firmware version: {}'.format(result)
#Только для ТРМ251


if devName == 'TPM251':
    result = owenDev.GetIEEE32('r.oUt')
    print 'Output power: {}'.format(result)
#считаем хэш параметра rEAd
hashREAD=owenDev.GetHash('rEAd')
#читаем с базового адреса
result=owenDev.GetIEEE32(hashREAD,0,withTime=True)
#можно и так
result1=owenDev.GetIEEE32('rEAd',0,withTime=True)['value']
#пример обработки исколЮчения, анализирует ошибку обрыв термопары
try:
    #читаем с адреса базовый+1
    result2=owenDev.GetIEEE32(hashREAD,1,withTime=True)    
except Owen.OwenUnpackError as e:
    #обрабатываем ошибку раскодировки данных
    result2 = None
    if len(e.data) == 1:
        #это код ошибки                
        if ord(e.data[0]) == 0xfd:
            #это обрыв термопары
            print 'Owen device::Sensor is damaged!'
    else:
        #бросаем исклЮчение дальше
        raise 'Owen device::Error when getting value!'    
except:
    #бросаем исклЮчение дальше
    raise 'Owen device::Error when getting value!'        
print 'Response from base address: ',result1
print 'Response from base+1 address: ',result2
