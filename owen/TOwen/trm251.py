# -*- coding: utf8 -*-
import Owen 

class TRM251(Owen.OwenDevice):
    def __init__(self,serialPort=None,address=16):
        Owen.OwenDevice.__init__(self,serialPort,address)
        self.hashROUT=self.GetHash('r.oUt')
        self.hashRST=self.GetHash('r.St')
        self.hashREAD=self.GetHash('rEAd')

    def GetTemperature(self,inputNumber=1):# Возвращает температуру на входе inputNumber, нумерация входов с единицы
        # запрашиваем температуру со временем
        try:
            temp = self.GetIEEE32(self.hashREAD,inputNumber-1,withTime=True)['value']
        except Owen.OwenUnpackError as e:
            #print list(e.data),len(e.data)
            temp = None
            if len(e.data) == 1:
                #это код ошибки                
                if ord(e.data[0]) == 0xfd:
                    print 'TRM251::Sensor is damaged!'
        except:
            raise 'TRM251::Error when getting temp!'
        return temp
        
    def GetPower(self):# Возвращает выходную мощность
        return self.GetIEEE32(self.hashROUT)

    def GetFilterTime(self):# Постоянная времени цифрового фильтра
        return self.GetInt16ByName('in.Fd')

    def GetFilterBand(self):# Полоса цифрового фильтра
        return self.GetInt16ByName('in.FG')
    