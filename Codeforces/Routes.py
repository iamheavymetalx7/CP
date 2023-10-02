# /**
# * author:Hisoka-TheMagician
# * created: 26/08/2023 11:12 Chennai, India
# **/
        




                                                                                                                        

from __future__ import division, print_function

import os,sys
#sys.setrecursionlimit(9*10**8)
from io import BytesIO, IOBase

if sys.version_info[0] < 3:
    from __builtin__ import xrange as range
    from future_builtins import ascii, filter, hex, map, oct, zip

from bisect import bisect_left as lower_bound, bisect_right as upper_bound 

from math import sqrt
def lmii():
    return list(map(int,input().split()))

def ii():
    return int(input())

def si():
    return str(input())
def lmsi():
    return list(map(str,input().split()))
def mii():
    return map(int,input().split())

def msi():
    return map(str,input().split())

i2c = lambda n: chr(ord('a') + n)
c2i = lambda c: ord(c) - ord('a')

import threading
def dmain():
    sys.setrecursionlimit(1000000)
    threading.stack_size(1024000)
    thread = threading.Thread(target=main)
    thread.start()


def joro(L):
    return(''.join(map(str, L)))


def decimalToBinary(n): return bin(n).replace("0b","")


def isprime(n):
    for i in range(2,int(n**0.5)+1):
        if n%i==0:
            return False
    return True

 
 
def SieveOfEratosthenes(n):
    prime = [True for i in range(n + 1)]
    p = 2
    li = []
    while (p * p <= n):
        if (prime[p] == True):
            for i in range(p * p, n + 1, p):
                prime[i] = False
        p += 1
 
    for p in range(2, len(prime)):
        if prime[p]:
            li.append(p)
    return li
 
 
def primefactors(n):
    factors = []
    while (n % 2 == 0):
        factors.append(2)
        n //= 2
    for i in range(3, int(sqrt(n)) + 1, 2):  # only odd factors left
        while n % i == 0:
            factors.append(i)
            n //= i
    if n > 2:  # incase of prime
        factors.append(n)
    return factors
         
    
from os import path
def read():
     if (path.exists('input.txt')):
        sys.stdin  = open('input.txt', 'r')  
        sys.stdout = open('output.txt', 'w') 
 
def tr(n):
    return n*(n+1)//2

from heapq import *
        
from collections import Counter, defaultdict, deque

def solve():
    import sys
    input =sys.stdin.buffer.readline
    
    k=ii()
    n=ii()
    m=ii()

    nnn=n*(n-1)//2

    adj=[[] for i in range(n)]
    
    for _ in range(m):
        x,y,t,c=mii()
        x-=1;y-=1
        adj[x].append([y,t,c])
        adj[y].append([x,t,c])
    
    S=ii()-1
    D=ii()-1
    if k>1000 or k<1000 or S<0 or D<0 or S>n-1 or D>n-1 or m<1 or m>nnn:
        print("Error")
        return
    
    # print(S,D)

    inf = int(1e18)
    dist=[inf for _ in range(n)]
    distt =[inf for _ in range(n)]
    vis=[0]*(n)
    parent=[0]*(n)

    def djikstra(S,D,k):
        pq=[]
        heappush(pq,[0,S])
        dist[S]=0
        distt[S]=0
        parent[S]=-1

        while pq:
            p = heappop(pq)
            if p[1]==D:
                return distt[D]
            x=p[1]
            for u,t,c in adj[x]:
                # print(u,t,c)
                if u==D:
                    if dist[u]>dist[x]+k*t+c:
                        dist[u] = dist[x]+k*t+c
                        distt[u]=distt[x]+t
                        parent[u]=x
                        heappush(pq,[dist[u],u])
                else:
                    if dist[u]>dist[x]+k*(t+1)+c:
                        dist[u]=dist[x]+k*(t+1)+c
                        distt[u]=distt[x]+t+1
                        parent[u]=x
                        heappush(pq,[dist[u],u])
        return -1

    def display(S,D):
        x=D
        v= []
        while x!=S:
            v.append(x)
            x=parent[x]
        v.append(x)
        v=v[::-1]
        for i in range(len(v)):
            print(v[i]+1,end ="")
            if i<len(v)-1:
                print("->",end="")
            else:
                print(" ",end = "")


    
    anst = djikstra(S,D,k)
    if anst==-1:
        print("Error")
    else:
        display(S,D)
        print(anst,dist[D])



def main():
    # for i in range(ii()):
        solve()
                
            
                
                
                
                
            
    
            
            
    
    
    
    
        
            
    
            
            
            
        
    
        
    
    
        
        
        

            
                    
                
                    
                    
                    
                    
                    
                    
        
                
        
        
       
    
           
          
          
                
            
        
                
    
        
        
        
       
            
                
        




# region fastio
# template taken from https://github.com/cheran-senthil/PyRival/blob/master/templates/template.py

BUFSIZE = 8192


class FastIO(IOBase):
    newlines = 0

    def __init__(self, file):
        self._fd = file.fileno()
        self.buffer = BytesIO()
        self.writable = "x" in file.mode or "r" not in file.mode
        self.write = self.buffer.write if self.writable else None

    def read(self):
        while True:
            b = os.read(self._fd, max(os.fstat(self._fd).st_size, BUFSIZE))
            if not b:
                break
            ptr = self.buffer.tell()
            self.buffer.seek(0, 2), self.buffer.write(b), self.buffer.seek(ptr)
        self.newlines = 0
        return self.buffer.read()

    def readline(self):
        while self.newlines == 0:
            b = os.read(self._fd, max(os.fstat(self._fd).st_size, BUFSIZE))
            self.newlines = b.count(b"\n") + (not b)
            ptr = self.buffer.tell()
            self.buffer.seek(0, 2), self.buffer.write(b), self.buffer.seek(ptr)
        self.newlines -= 1
        return self.buffer.readline()

    def flush(self):
        if self.writable:
            os.write(self._fd, self.buffer.getvalue())
            self.buffer.truncate(0), self.buffer.seek(0)


class IOWrapper(IOBase):
    def __init__(self, file):
        self.buffer = FastIO(file)
        self.flush = self.buffer.flush
        self.writable = self.buffer.writable
        self.write = lambda s: self.buffer.write(s.encode("ascii"))
        self.read = lambda: self.buffer.read().decode("ascii")
        self.readline = lambda: self.buffer.readline().decode("ascii")


def print(*args, **kwargs):
    """Prints the values to a stream, or to sys.stdout by default."""
    sep, file = kwargs.pop("sep", " "), kwargs.pop("file", sys.stdout)
    at_start = True
    for x in args:
        if not at_start:
            file.write(sep)
        file.write(str(x))
        at_start = False
    file.write(kwargs.pop("end", "\n"))
    if kwargs.pop("flush", False):
        file.flush()


if sys.version_info[0] < 3:
    sys.stdin, sys.stdout = FastIO(sys.stdin), FastIO(sys.stdout)
else:
    sys.stdin, sys.stdout = IOWrapper(sys.stdin), IOWrapper(sys.stdout)

input = lambda: sys.stdin.readline().rstrip("\r\n")

# endregion


if __name__ == "__main__":
    read()
    main()
    #dmain()

# Comment Read()