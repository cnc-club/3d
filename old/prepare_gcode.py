# -*- coding: utf-8 -*-
import sys 
import re
import os

path = "/home/cnc/linuxcnc/nc_files/3dlms-layers"
layer_thikness = 0.2
feed = 5000
scale = .5
x_offset = -50
y_offset = -50

f = sys.argv[1]
s=open(f,"r").read()

full = len(s)



s = s.split("(Layer start)")
layers = []
progress = 0
k = 0
for layer in s :
	progress += len(layer)
	print >> sys.stderr, "FILTER_PROGRESS=%d"%(progress*50/full)
	layers.append("")
	for l in layer.split("\n") :

		r = re.match("G0?1\s*X([-0-9\.]+)\s*Y([-0-9\.]+)",l)
		if r :
			x,y = r.groups()
			r = re.search("F([-0-9\.]+)",l)
			if r :
				f = float(r.group(1))
			layers[-1] += "G0%d X%s Y%s\n"%( 0 if f>7000 else 1, float(x)*scale+x_offset,float(y)*scale+y_offset) 


i = 0


for layer in layers :
	print >> sys.stderr, "FILTER_PROGRESS=%d"%(i*50/len(layers) +50)
	if layer == "" :
		continue
	print "M100 P%s"%i

	layer += "F3000"+layer
	layer += "F2000"+layer
	
	layer = layer + "\nM02\n"

	f = open(path+"/%04d.ngc"%i,"w")

	f.write(layer)
	f.close()
		
	print "O<layer> CALL [%s]"%layer_thikness
	i+=1
			
print "M02"


