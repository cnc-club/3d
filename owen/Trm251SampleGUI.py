# -*- coding: cp1251 -*-
from TOwen import trm251
from TSystem import MySerial as Serial
import thread as threadModule
import time
import wx
import wx.lib.newevent
import sys

#создаем последовательный порт
try:
    #COM = Serial.ComPort(0, 9600, timeout=1)#открываем COM1
    COM = Serial.ComPort("11", 9600, timeout=1)#открываем COM12
except:
    raise Exception('Error openning port!')

# This creates a new Event class and a EVT binder function
(UpdateBarEvent, EVT_UPDATE_INFO) = wx.lib.newevent.NewEvent()

#чтение данных происходит в этом потоке
class PidRegulatorThread:
    def __init__(self, win):
        self.win = win
        self.Temp = 0
        self.Power = 0
        self.running=False
        self.keepGoing = False
	self.pidReg=trm251.TRM251(COM,16);
	#self.pidReg=trm251.TRM251(None,16);
        
    def Start(self):        
        if not self.running:
            self.keepGoing = self.running = True
            threadModule.start_new_thread(self.Run, ())

    def Stop(self):
        self.keepGoing = False

    def IsRunning(self):
        return self.running

    def Run(self):
        self.Temp=0;
        self.Power=0;        
        state=1
        while self.keepGoing:                        
            time.sleep(1.0)
            #читаем температуру
            try:
                self.Temp = self.pidReg.GetTemperature()
            except:
                self.Temp = None
            #читаем мощность
            try:
                self.Power = self.pidReg.GetPower()
            except:
                self.Power = None
            #print 'ON::State: {} power: {} temp: {}'.format(state,self.Power,self.Temp);
            evt = UpdateBarEvent(Power = self.Power, Temp = self.Temp)
            wx.PostEvent(self.win, evt)            
        self.running = False
       
        


class MyFrame(wx.Frame):
    """
    This is MyFrame.  It just shows a few controls on a wxPanel,
    and has a simple menu.
    """
    def __init__(self, parent, title):
        wx.Frame.__init__(self, parent, -1, title,
                          pos=(150, 150), size=(230, 250))

        # Create the menubar
        menuBar = wx.MenuBar()

        # and a menu 
        menu = wx.Menu()

        # add an item to the menu, using \tKeyName automatically
        # creates an accelerator, the third param is some help text
        # that will show up in the statusbar
        menu.Append(wx.ID_EXIT, "В&ыход\tAlt-X", "Exit this simple sample")

        # bind the menu event to an event handler
        self.Bind(wx.EVT_MENU, self.OnTimeToClose, id=wx.ID_EXIT)

        # and put the menu on the menubar
        menuBar.Append(menu, "&Файл")
        self.SetMenuBar(menuBar)

        self.CreateStatusBar()
        

        # Now create the Panel to put the other controls on.
        panel = wx.Panel(self)

        # and a few controls
        textTemp = wx.StaticText(panel, -1, 'Температура:0')
        textTemp.SetFont(wx.Font(14, wx.SWISS, wx.NORMAL, wx.BOLD))
        textTemp.SetSize(textTemp.GetBestSize())
        self.Temp=textTemp;
        textPower = wx.StaticText(panel, -1, 'Мощность:0')
        textPower.SetFont(wx.Font(14, wx.SWISS, wx.NORMAL, wx.BOLD))
        textPower.SetSize(textPower.GetBestSize())
        self.Power=textPower;
        
        self.btnStart = wx.Button(panel, -1, "Старт")
        self.btnStop = wx.Button(panel, -1, "Стоп")
        self.btnStop.Disable()

        # bind the button events to handlers
        self.Bind(wx.EVT_BUTTON, self.OnStart, self.btnStart)
        self.Bind(wx.EVT_BUTTON, self.OnStop, self.btnStop)
        
        self.thread=PidRegulatorThread(self)
        
        self.Bind(EVT_UPDATE_INFO, self.OnUpdate)

        # Use a sizer to layout the controls, stacked vertically and with
        # a 10 pixel border around each
        sizer = wx.BoxSizer(wx.VERTICAL)
        sizer.Add(textTemp, 0, wx.ALL, 10)
        sizer.Add(textPower, 0, wx.ALL, 10)
        #panel.SetSizer(sizer)

        #sizer = wx.BoxSizer(wx.HORIZONTAL)
        sizer.Add(self.btnStart, 0, wx.ALL, 10)
        sizer.Add(self.btnStop, 0, wx.ALL, 10)
        panel.SetSizer(sizer)
        panel.Layout()
        
        self.Bind(wx.EVT_CLOSE, self.OnCloseWindow) 

    def OnStart(self, evt):       
        #print "Starting thread!"
        self.btnStart.SetLabel('Процесс чтения данных запущен!');
        self.btnStart.SetSize(self.btnStart.GetBestSize())        
        self.btnStop.Enable()
        self.btnStart.Disable()
        self.thread.Start()

    def OnStop(self, evt):
        #print "Stopping thread!"
        self.btnStart.SetLabel('Старт');
        self.btnStart.SetSize(self.btnStart.GetBestSize())                
        self.btnStart.Enable()
        self.btnStop.Disable()
        self.thread.Stop()
        
    def OnUpdate(self, evt):
        #self.graph.SetValue(evt.barNum, evt.value)
        #self.graph.Refresh(False)
        if evt.Temp == None:
            self.Temp.SetLabel('Температура: Ошибка!')
        else:
            self.Temp.SetLabel('Температура: {0:.2f}'.format(evt.Temp))
        if evt.Power == None:
            self.Power.SetLabel('Мощность: Ошибка!')
        else:
            self.Power.SetLabel('Мощность: {0:.2f}'.format(evt.Power))
        pass
        
    def OnCloseWindow(self, evt):
        busy = wx.BusyInfo("Останавливаем поток чтения данных...")
        wx.Yield()

        self.thread.Stop()

        running = True
        while running:
            running = self.thread.IsRunning()
            time.sleep(0.1)

        self.Destroy()  
        
    def OnTimeToClose(self, evt):
        print "See you later!"
        self.Close()        

class MyApp(wx.App):
    def OnInit(self):
        # Redirect stdou/stderr
        sys.stderr = open("wx_stderr.log", "w")
        sys.stdout = open("wx_stdout.log", "w")

        
        # Do the inits      
        frame = MyFrame(None, "Регулятор")
        self.SetTopWindow(frame)
        frame.Show(True)
        return True
        

app = MyApp(redirect=True,filename="wxlogfile.log")
app.MainLoop()

        
