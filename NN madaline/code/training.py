from nnclass2 import ll
from nnclass2 import chweight
from nnclass2 import chref
b1=0.3
b2=0.15
w11=0.05
w12=0.1
w21=0.2
w22=0.2
b3=0.5
v1=0.5
v2=0.5
#x1=[-8.697,-10.659,-13.494,-12.786,-14.093,-7.873,-8.349,-7.644,-6.314,-5.947]#loudness
#x2=[155.007,148.462,112.909,117.429,141.536,121.281,85.03,112.918,128.929,97.303]#tempo
#t=[-1,-1,-1,-1,-1,1,1,1,1,1]
file=open("train.txt","r")
arr=file.read()
file.close()
arr=arr.split("\n")
x1=arr[0].split(",")
x2=arr[1].split(",")
t=arr[2].split(",")
y=[]
for i in range(len(t)):
    x1[i]=float(x1[i])
    x2[i]=float(x2[i])
    t[i]=float(t[i])
    y.append(0)
al=float(arr[3])
epoch=1
print("updated values")
print('{:>7}'.format("x1"),end="\t")
print('{:>7}'.format("x2"),end="\t")
print('{:>7}'.format("z1out"),end="  ")
print('{:>7}'.format("z2out"),end="  ")
print('{:>2}'.format("z1"),end=" ")
print('{:>2}'.format("z2"),end="  ")
print('{:>7}'.format("yin"),end="  ")
print('{:>2}'.format("y"),end=" ")
print('{:>2}'.format("t"),end="  ")
print('{:>7}'.format("w11"),end="  ")
print('{:>7}'.format("w21"),end="  ")
print('{:>7}'.format("b1"),end="  ")
print('{:>7}'.format("w12"),end="  ")
print('{:>7}'.format("w22"),end="  ")
print('{:>7}'.format("b2"))
stop=1
size=len(x1)
m1=sum(x1)/float(size)
m2=sum(x2)/float(size)
for i in range(size):
    x1[i]=x1[i]/m1
    x2[i]=x2[i]/m2
    x1[i]=float("{0:.4f}".format(x1[i]))
    x2[i]=float("{0:.4f}".format(x2[i]))
#for i in range(size):x2[i]=float("{0:.4f}".format(x2[i]))
while(stop!=0):
    print("epoch ",epoch,":")
    print()
    for i in range(size):
        print('{:>7}'.format(x1[i]),end=" ")
        print('{:>7}'.format(x2[i]),end="  ")
        ll.lladr[0].clear()
        ll.lladr[1].clear()
        ll.neurons=[0,0]
        chweight(2)
        chref(0)
        a=ll()
        a.insert(x1[i],1)
        a.insert("x1",1)
        a.insert(w11,1)
        a.insert("z1",1)
        a.insert("z1out",1)
        #a.merg(1)
        #print(a.size(2))
        adr1=a.address(1)
        b=ll()
        b.insert(x2[i],1)
        b.insert("x2",1)
        b.insert(w21,1)
        b.insert("z1",1)
        #b.merg(2)
        #print(b.size(2))
        adr2=b.address(1)
        #print(c.size(2))
        b.dmerg(adr1[3],1)
        #print(a.size(1))
        #print(b.size(1))

        a.insert(w12,2)
        a.insert("z2",2)
        a.insert("z2out",2)
        #a.merg(1)
        #print(a.size(2))
        adr1=a.address(2)
        b.insert(w22,2)
        b.insert("z2",2)

        #b.merg(2)
        #print(b.size(2))
        adr2=b.address(2)
        #print(c.size(2))
        b.dmerg(adr1[3],2)
        #print(a.size(2))
        #print(b.size(2))

        z1out=float("{0:.4f}".format(ll.out(1,b1)))
        z2out=float("{0:.4f}".format(ll.out(2,b2)))
        
        print('{:>7}'.format(z1out),end="  ")
        print('{:>7}'.format(z2out),end=" ")

        z1=1 if z1out>=0 else -1
        z2=1 if z2out>=0 else -1

        print('{:>2}'.format(z1),end=" ")
        print('{:>2}'.format(z2),end="  ")

        #################################

        chref(1)
        chweight(1)
        za=ll()
        za.insert(z1,1)
        za.insert("z1",1)
        za.insert(v1,1)
        za.insert("o1",1)
        za.insert("y1",1)
        #a.merg(1)
        #print(a.size(2))
        adr1=za.address(1)
        zb=ll()
        zb.insert(z2,1)
        zb.insert("z2",1)
        zb.insert(v2,1)
        zb.insert("o1",1)
        #b.merg(2)
        #print(b.size(2))
        adr2=zb.address(1)
        #print(c.size(2))
        zb.dmerg(adr1[3],1)
        #print(a.size(1))
        #print(b.size(1))
        #print()

        yin=ll.yout([b3])
        print('{:>7}'.format(yin),end="  ")

        y[i]=1 if yin>=0 else -1
        print('{:>2}'.format(y[i]),end=" ")

        print('{:>2}'.format(t[i]),end="  ")
        
        if(t[i]!=y):
            if(t[i]<0):
                if(z1out>0):
                    b1=float("{0:.4f}".format(b1+al*(t[i]-z1out)))
                    w11=float("{0:.4f}".format(w11+al*(t[i]-z1out)*x1[i]))
                    w21=float("{0:.4f}".format(w21+al*(t[i]-z1out)*x2[i]))
                if(z2out>0):
                    b2=float("{0:.4f}".format(b2+al*(t[i]-z2out)))
                    w12=float("{0:.4f}".format(w12+al*(t[i]-z2out)*x1[i]))
                    w22=float("{0:.4f}".format(w22+al*(t[i]-z2out)*x2[i]))
            else:
                if(abs(z1out)<abs(z2out)):
                    b1=float("{0:.4f}".format(b1+al*(t[i]-z1out)))
                    w11=float("{0:.4f}".format(w11+al*(t[i]-z1out)*x1[i]))
                    w21=float("{0:.4f}".format(w21+al*(t[i]-z1out)*x2[i]))
                else:
                    b2=float("{0:.4f}".format(b2+al*(t[i]-z2out)))
                    w12=float("{0:.4f}".format(w12+al*(t[i]-z2out)*x1[i]))
                    w22=float("{0:.4f}".format(w22+al*(t[i]-z2out)*x2[i]))

        #else:

        
        print('{:>7}'.format(w11),end="  ")
        print('{:>7}'.format(w21),end="  ")
        print('{:>7}'.format(b1),end="  ")
        print('{:>7}'.format(w12),end="  ")
        print('{:>7}'.format(w22),end="  ")
        print('{:>7}'.format(b2))

    print()
    print(y,t)
    stop=(y>t)-(y<t)
    #print(stop)
    print()
    epoch=epoch+1
ww=w12
w12=w21
w21=ww
file = open("final weights.txt","w") 
file.write(str(w11))
file.write("\n")
file.write(str(w21))
file.write("\n")
file.write(str(b1))
file.write("\n")
file.write(str(w12))
file.write("\n")
file.write(str(w22))
file.write("\n")
file.write(str(b2))
file.write("\n")
file.write(str(m1))
file.write("\n")
file.write(str(m2))
file.close() 
