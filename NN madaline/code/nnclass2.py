import random
weights=3
refrence=0
def chweight(weight):
    global weights
    weights=weight
def chref(ref):
    global refrence
    refrence=ref
class node(object):
    def __init__(self,data=None):
        self.data=data
        self.n=[]
        for h in range(weights):
            self.n.append(0)
            self.n[h]=None
        return
    
    def gdata(self):
        return self.data

    def next(self,i):
        return self.n[i-1]
    

class ll:
    tcount=0
    neurons=[0,0]
    y=[]
    nds=[]
    lladr=[[],[]]
    def __init__(self):
        self.head=None
        global refrence
        ll.lladr[refrence].append(0)
        ll.lladr[refrence][ll.neurons[refrence]]=self
        ll.neurons[refrence]=ll.neurons[refrence]+1
        return
    
    def insert(self,data,i):
        new_n=node(data)
        if(self.tcount==0):
            self.head=new_n
            self.tcount=self.tcount+1
            ll.nds.append(0)
            ll.nds[ll.neurons[refrence]-1]=self.head
        elif(self.tcount==1):
            current=self.head
            while current.next(i):
                current=current.next(i)
            for h in range(weights):
                current.n[h-1]=new_n
            self.tcount=self.tcount+1
        else:
            current=self.head
            while current.next(i):
                current=current.next(i)
            current.n[i-1]=new_n

    def size(self,i):
        current=self.head
        count=0
        while current:
            print("->",current.data,end=' ')
            count=count+1
            current=current.next(i)
        print(end="\n")
        return count


    def address(self,j):
        current=self.head
        address=[]
        i=0
        while current:
            address.append(0)
            address[i]=current
            #print(current)
            current=current.next(j)
            i=i+1
        return address

    def merg(self,data):
        new_n=node(data)
        for h in range(weights):
            current=self.head
            while current.next(1):
                current=current.next(h)
            current.n[h-1]=new_n
        
    def dmerg(self,adr,j):
        current=self.head
        while current.next(j).next(j):
            current=current.next(j)
        current.n[j-1]=adr

    def so(self,i):
        current=self.head
        ss=current.data*current.next(i).next(i).data
        ll.y.append(ss)

    def out(i,bias=0):
        tot=0
        global refrence
        for h in range(len(ll.lladr[refrence])):
            ll.lladr[refrence][h].so(i)
            tot=tot+ll.y[h]
        ll.y.clear()
        return tot+bias

    def yout(bias=[0,0,0]):
        tot=0
        if(len(bias)<weights):
            print("wrong bias given")
            return
        else:
            for h in range(weights):
                tot=tot+ll.out(h+1)+bias[h]
            return tot
            
