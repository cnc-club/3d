# -*- coding: cp1251 -*-
from TOwen import trm251
from TSystem import MySerial as Serial
import time

#создаем последовательный порт
try:
    COM = Serial.ComPort(11, 9600, timeout=0.3)#открываем COM12
except:
    raise Exception('Error openning port!')

COM.LoggingIsOn=True#включаем логирование в файл

pidReg=trm251.TRM251(COM,16);#настоящий порт
#pidReg=trm251.TRM251(None,16);#тестовые данные

#pidReg.Debug = True # вклЮчаем вывод отладочных сообщений

NS = pidReg.GetNetworkSettings() # читаем сетевые настройки устройства

print NS

State = pidReg.GetInt16('r.st')
print State
print pidReg.owenProtocol
#print pidReg.GetFilterTime()

def Run():
    Temp=0;
    Power=0;        
    state=1
    while 1==1:                        
        time.sleep(1.0)
        Temp=pidReg.GetTemperature(1)
        if state==1 or state==4:
            Power=pidReg.GetPower()			
            print 'ON::State: {} power: {} temp: {}'.format(state,Power,Temp);
        else:
            power=0;
       
        
Run()

        