# -*- coding: utf8 -*-
import serial
import time

#класс последовательного порта с логированием данных
class ComPort(serial.Serial):
    def __init__(self, port=None, baudrate=9600, bytesize=8, parity='N', stopbits=1, timeout=None, xonxoff=0, \
                 rtscts=0, writeTimeout=None, dsrdtr=None):
        serial.Serial.__init__(self, port, baudrate, bytesize, parity, stopbits, timeout, xonxoff, rtscts, \
                                   writeTimeout, dsrdtr)                        
        self.LoggingIsOn=False;
                
    def log(self, buffer, obj_name=None, action=None):
        if self.LoggingIsOn:            
            log_file = open('ComLog.txt','a')
            tm = time.ctime(time.time())
            timeStr='Time: {}\n'.format(tm)
            #ObjectStr='Object: {}\n'.format(obj_name)        
            ObjectStr=''
            str2log=''
            if len(buffer)>0:
                for char in buffer:
                    str2log=str2log+'{0:#x}({0}) '.format(ord(char))
                dataStr='Data {}: {}\n\n'.format(action,str2log)
            else:
                dataStr='Data when {} is empty\n\n'.format(action)        
            log_file.write('{} {} {}'.format(timeStr,ObjectStr,dataStr))
            log_file.close()
        
    def write(self, buffer, obj_name=None):
        if self.isOpen():
            #self.flush()
            serial.Serial.write(self,buffer)
            #self.flushOutput()
            self.log(buffer, obj_name, 'writing')
            return (True,'')
        else:
            self.log(buffer,obj_name,'writing::error:port_not_open')                
            raise Exception('ComPort::writing:port is not open!')                
        
    def read(self, size, obj_name=None):
        if self.isOpen():
            buffer = serial.Serial.read(self,size)
            self.log(buffer, obj_name, 'reading')            
            #self.flushInput()
            return (True,buffer)
        else:
            self.log(buffer, obj_name, 'reading::error:port_not_open')                        
            raise Exception('ComPort::reading:port is not open!')
    
    def test(self):
        raise Exception('Test not implemented!')
   