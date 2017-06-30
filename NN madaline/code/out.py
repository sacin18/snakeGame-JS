from nnclass2 import ll
from nnclass2 import chweight
from nnclass2 import chref
#-1.8871  -0.9703   2.9417  -0.8556  -1.3566  -0.7696
file = open("final weights.txt", "r")
mods=file.read()
mods=mods.split("\n")
w11=float(mods[0])
w21=float(mods[1])
b1=float(mods[2])
w12=float(mods[3])
w22=float(mods[4])
b2=float(mods[5])
m1=float(mods[6])
m2=float(mods[7])
file.close()
v1=0.5
v2=0.5
b3=0.5
x1=input("loudness :: ")
x2=input("tempo :: ")
x1=float(x1)/m1
x2=float(x2)/m2
x1=float("{:.4}".format(x1))
x2=float("{:.4}".format(x2))

print("x1 :",x1)
print("x2 :",x2)
chweight(2)
chref(0)
a=ll()
a.insert(x1,1)
a.insert("x1",1)
a.insert(w11,1)
a.insert("z1",1)
a.insert("z1out",1)
#a.merg(1)
#print(a.size(2))
adr1=a.address(1)
b=ll()
b.insert(x2,1)
b.insert("x2",1)
b.insert(w12,1)
b.insert("z1",1)
#b.merg(2)
#print(b.size(2))
adr2=b.address(1)
#print(c.size(2))
b.dmerg(adr1[3],1)
print(a.size(1))
print(b.size(1))

a.insert(w21,2)
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
print(a.size(2))
print(b.size(2))

z1out=ll.out(1,b1)
z2out=ll.out(2,b2)
print()
print("z1out",z1out)
print("z2out",z2out)
print()

z1=1 if z1out>=0 else -1
z2=1 if z2out>=0 else -1

print("z1",z1)
print("z2",z2)
print()

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
print(a.size(1))
print(b.size(1))
print()

print("y",ll.yout([b3]))
yout=1 if ll.yout([b3])>=0 else -1
print("yout",yout)
if(yout==-1):
    print("classic rock and pop")
else:
    print("hip hop")
    
