
x0,x1 = -50., -100.
y0,y1 = 20., 40.

x1 = x0+20.
y1 = y0+20.

x0,x1 = min(x0,x1), max(x0,x1)
y0,y1 = min(y0,y1), max(y0,y1)
step = 1. 
x = x0
y = y0
print "F1000"
for k in range(5):
    x = x0
    y = y0

    for i in range(int((x1-x0)/step/2)) :
        
        print "G0 X%s Y%s" %(x,y0) 
        print "G1 X%s Y%s" %(x0,y) 
        x+=step
        y+=step
        print "G0 X%s Y%s" %(x0,y) 
        print "G1 X%s Y%s" %(x,y0) 
        x+=step
        y+=step
        
        
    print "G0 X%s Y%s" %(x0,y0) 
    print "G1 X%s Y%s" %(x1,y0) 
    print "G1 X%s Y%s" %(x0,y1) 
    print "G1 X%s Y%s" %(x0,y0) 
    
"""x = x0
for i in range(int((x1-x0)/step/2)) :

    print "G0 X%s Y%s" %(x1-x,y1) 
    print "G1 X%s Y%s" %(x1,y1-x) 
    x+=step
    print "G0 X%s Y%s" %(x1,y1-x) 
    print "G1 X%s Y%s" %(x1-x,y1) 
    x+=step
    
"""
