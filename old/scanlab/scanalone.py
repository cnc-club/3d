#!/usr/bin/python
# -*- coding: utf-8 -*-
import os
import sys
import time
import re 

from struct import *

import usb.core
import usb.util

PRINT = False

class ScanAlone():
	scale = 32767./100. #bits/mm
	jump_speed = 2500.  #mm/sec
	mark_speed = 250.  #mm/sec
	laser_on_delay = 100
	laser_off_delay = 100
	
	commands_len = 0
	def __init__(self):
		os.environ['PYUSB_LOG_FILENAME'] = 'debug'
		self.dev = usb.core.find(idVendor=0x0451, idProduct=0x9001)
		# was it found?
		if self.dev is None:
			raise ValueError('Device not found')
		try:
			dev.detach_kernel_driver(0)
		except: # this usually mean that kernel driver has already been dettached
			pass
		
		cfg = self.dev.get_active_configuration()	
		alt = usb.util.find_descriptor(cfg, find_all=True, bInterfaceNumber=1)
		intf = cfg[(0,0)]
		self.ep = usb.util.find_descriptor(
			intf,
			custom_match = lambda e: usb.util.endpoint_direction(e.bEndpointAddress) == usb.util.ENDPOINT_IN
			)


		# set the active configuration, the device has 2 configurations you can see them
		# by using: lsusb -vvv -d 0x0b40:
		# this device has configurations 1 and 2 I'm using the first one, not sure at the
		# moment if 2nd would work the same
		self.dev.set_configuration(1)
		
		# send corection file
		path = os.path.dirname(os.path.realpath(__file__))
		f = open(path+"/Cor_1to1.ctb","r").read()
		offset = 0x6000
		while len(f)>0 :
			s = f[:58]
			self.send(pack("=cHH", chr(len(s)), offset,0)+s, False )
			f = f[58:]
			offset += 58
					
		
		

	def send(self,p, pr=PRINT):
		r = [ord(i) for i in p]
		if pr :
			print "Send ->",
			for i in r:
				print "%02x"%i,
		c = self.dev.write(1, p), "bytes"				
		if pr :
			print  "--", c

	def get(self,depth=0, pr=PRINT):
		if depth>5 : return "Error!"
		try :
			bytes = self.dev.read(0x81,32, 100)
		except :	
			raw = self.pack_request(0x94, 0x00, 0x06, 0x00, 0x00)
			self.dev.write(1, raw)
			return self.get(depth+1)	
		if pr :
			r = [i for i in bytes]
			print "Get  ->",
			for i in r:
				print "%02x"%i,
			print 
		return bytes
	


	def pack_request(self, *arg):
		return ''.join([chr(c) for c in arg])


	def send_command(self, *arg):
		if len(arg) == 1 and arg[0].__class__ == "".__class__ :
			arg = [ord(i) for i in arg[0]]
		p = [0x14,0x00,0x06,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00]
		p[len(p)-len(arg):] = arg
		self.send(self.pack_request(*p))
	
	def execute(self):
		self.send_command(					 0x22,0x00)
		#send(pack_request(0x08, 0x70, 0x06, 0x04, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00))
		

	def get_status(self):
		bytes = self.get()
		bytes = [i for i in bytes]
		bytes[:4] = [0x14,0x00,0x06,0x00]
		bytes[-2:] = [0x54,0x00]
		self.send_command(*bytes)
		bytes = self.get()
		s = "".join([chr(i) for i in bytes]) 
		return unpack("=xxxxxxxxxxxxxxxxxxxHHH",s)

	def print_status(self):
		a,b,c = self.get_status()
		print "State: %s, Line: %s of %s"%(b,a/4,self.commands_len)
		return a,b,c

	def set_end_of_list(self):
		pass ### send 01 00 00 00 command at gcode
	

	def clear_list(self):
		self.send_command(					 0x53,0x00)


	
	def select_list(self,a=1):
		if a==1:
						# 0
			self.send_command(					 0x18,0x00)
		else:
						# 500 000
			self.send_command(0x20,0xA1,0x07,0x00,0x18,0x00)


	def set_speed(self,t,v):
		# v in mm/sec
		if v<=0 :
			v = 100
		v = v * self.scale # bits/sec	
		v = min(65534,round(25600.*1000./v))
		return pack("hHhh", t, v,0,0 )
		

	def send_code(self, code) :
		# code G0?(0|1) X([-0-9.]+) Y([-0-9.]+)
	
		commands = []
		commands.append(self.set_speed(0x0C,self.jump_speed))		# set jump speed
		commands.append(self.set_speed(0x0D,self.mark_speed))		# set mark speed

		#		set_standby_list(100*8, // half of the laser standby pulse period
		#						//  [1/8us]
		#				1*8);  // standby pulse width [1/8us]
		commands.append( pack("hhhh",0x14,1,100*8,1*8) )

		#set_laser_timing(50,	// half of the laser signal period
		#				 40,	// pulse widths of signal LASER1
		#				 40,	// pulse widths of signal LASER2
		#				 0);	// time base; 0 corresponds to 1 microsecond; 
		#						// otherwise the time base is 1/8 microseconds
		commands.append( pack("hhhh",0x1A,100,200,10) )
			
		#		set_scanner_delays(50,  // jump delay [10us]
		#				   20,  // mark delay [10us]
		#				   10); // polygon delay [10us]
		commands.append( pack("hhhh",0x0F,50,20,10) )
		
		#laser_on_delay signed 16-bit value. Allowed range: [ – 8000 ... +8000]
		#laser_off_delay signed 16-bit value. Allowed range: [+2 ... +8000]
		#C: void set_laser_delays(short laser_on_delay, short laser_off_delay);
		commands.append(pack("hhhh",0x0E,self.laser_on_delay,self.laser_off_delay,0)) # set laser delays ()
		
		
		X=0
		Y=0
		G=0
		for s in code.split("\n") :		
			if s.find(";") > 0:		# remove comments
				s = s[:s.find(";")]
			if s.find("(") > 0:	 # remove comments
				s = s[:s.find("(")]
				
			def get_code(code,s):
				r = re.search(code+"([-0-9.]+)",s,re.I)
				if r : 
					return float(r.group(1))
				else :
					return None	
			
			F = get_code("F",s)
			if F :
				commands.append( self.set_speed(0x0D, F) ) 		# set mark speed
			PRINT = True	
			print (s)
			t = get_code("G",s) 
			if t!=None: 
				G = t
				t = get_code("X",s) 
				if t!=None: 
					X = t
				t = get_code("Y",s) 
				if t!=None: 
					Y = t
				if PRINT :
					print "G%d X%0.2f Y%0.2f"%(G,X,Y)
				c = pack("hhhh",
							2 if G==0 else 3,
							round(X*self.scale),
							round(Y*self.scale),
							0
					)
				commands.append(c)						
				
		commands.append(pack("hhhh",1,0,0,0)) # list_end
		self.commands_len = len(commands)
		
		offset = 0
		while len(commands)>0:
			c = commands[:7]
			self.send( pack("=cHH",chr(len(c)*4*2), offset, 4)+"".join(c) ) 
			commands=commands[7:]
			offset += 7*4*2
		
		# 5 reserved bytes. 
		# 00 - packet size
		# 00 - shift address
		# 00 - ---""---
		# 00 00 - command
		
		# 04 00 - list commands
		
		
		# 02 00 xx xx yy yy 00 00  - jump_abs
		# 03 00 xx xx yy yy 00 00  - mark_abs
		# 04 00 xx xx yy yy 00 00  - jump_rel
		# 05 00 xx xx yy yy 00 00  - mark_rel
		
		# 08 70 06 04 00 01 
#		08 70 06 04 00 01 00 00 00 00 00 00 00
		
		
#		14 00 06 00 00 00 00 00 00 00 00 00 00 00 00 00 00 02 00 00 00 00 00 22 00	  



def main():
	#initialising debuging - don't have a clue if this will work
	scan = ScanAlone()
	

	if len(sys.argv)>1 :
		gcode = open(sys.argv[1],"r").read()
	else : 
		print "No input file!"
		print "Usage pyhton scanalone.py file.ngc"
		return		
	scan.select_list(1)
	scan.clear_list()
	

	scan.send_command(0x00,0x00,0x2A,0x00) #set_laser_mode(0);			  // select CO2 mode
	scan.send_command(pack("HHHHH",0,0 ,650,0x0D,0x1E)) #set_delay_mode(1,0,65000,0,0);  // use the variable polygon delay
		
	scan.send_code(gcode)	
	scan.get_status()

	scan.execute()
	
	a,b,c = scan.print_status()
	while b == 0 :
		a,b,c = scan.print_status()
		time.sleep(0.1)

	print "Done!"


if __name__ == '__main__':
  main()
