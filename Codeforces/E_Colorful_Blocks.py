# /**
# * author:Hisoka-TheMagician
# * created: 22/09/2023 17:20 Chennai, India
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


        
from collections import Counter, defaultdict, deque

def modfac(n,mod):
    facs=[1]
    f=1

    for m in range(1,n+1):
        f*=m
        f%=mod
        facs.append(f)
    
    inv = pow(f,mod-2,mod)
    invs=[1]*(n+1)
    invs[n]=inv
    for m in range(n,1,-1):
        inv*=m
        inv%=mod
        invs[m-1]=inv
    
    return facs,invs

mod = 998244353

'''
https://codeforces.com/blog/entry/77148?#comment-619270

Here is my approach: Consider we divide the n blocks into p sets of partitions and label them as n1,n2,n3,...,np. We could do it in (n-1)c(p-1) ways.

Another constraint is the total pairs of contiguous blocks with same color <=k. It means that (n1-1)+(n2-1)+....+(np-1)<=k which implies n1+n2+...+np-p<=k which implies n-p<=k thus we get p>=n-k

Now for coloring part of p sets can be done in m*((m-1)^(p-1)) ways.

So simply iterate p from n-k to n and add ((n-1)c(p-1)) * (m*((m-1)^(p-1))) to the answer.

'''
def nCr(n, r):
    return fac[n] * inv[n-r] * inv[r] % mod

fac,inv = modfac(int(2e5)+3,mod)

def solve():
    import sys
    input =sys.stdin.buffer.readline

    n,m,k=mii()
    ans =0

    for p in range(n-k,n+1):
        ans+= nCr(n-1,p-1)*m*pow(m-1,p-1,mod)
        ans%=mod
    print(ans)    
    

    
    
        
            
            
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