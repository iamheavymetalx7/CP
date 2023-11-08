# /**
# * author:Hisoka-TheMagician
# * created: 08/11/2023 14:21 Chennai, India
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

def solve():
    import sys
    input =sys.stdin.buffer.readline
    
    n =ii()
    a= lmii()

    cf = defaultdict(list)
    for i,x in enumerate(a):
        cf[x].append(i+1)

    idx=-1  
    perm = [0 for _ in range(n)]
    
    for i in range(n-1,-1,-1):
        if a[i]==0:
            idx=i
            perm[i]=n
            break
    left = set(i+1 for i in range(idx))
    right = set(i+1 for i in range(idx,n-1))
    tot = set(i for i in range(1,n))
    # print(tot)

    curr = idx

    for i in range(curr-1,-1,-1):
        if a[i]==0:
            perm[i]=curr
            left.discard(curr)
            tot.discard(curr)
            curr=i
    # print(perm)
            
    for i in range(n-1,idx+1,-1):
        # print(a[i],idx)
        if a[i]==idx+1:
            perm[i]=n-1
            right.discard(n-1)
            tot.discard(n-1)

            break
    # print(perm,"here")
    
    for i in range(n):
        if perm[i]==0:
            if len(cf[a[i]])==1 and perm[a[i]-1]!=0:
                perm[a[i]] =  perm[a[i]-1]-1
                tot.discard(perm[a[i]-1]-1)

    # print(perm)
    # print(left)
    # print(tot)
    total = sorted(tot)
    # print(total)
    j=0
    for i in range(n):
        if perm[i]==0:
            perm[i]=total[j]
            j+=1
            if perm[i]>perm[a[i]-1] and a[i]!=0:
                perm[i],perm[a[i]-1] = perm[a[i]-1],perm[i]
            # print(perm,"iiii")
    # print(perm)


    for i in range(n):

        while perm[i]>perm[a[i]-1] and a[i]!=0:
            # print(i,perm[i],perm[a[i]-1])
            perm[i],perm[a[i]-1] = perm[a[i]-1],perm[i]
            # print(perm,"duck")
    print(perm,"fin")
    print("*"*20)



# 12
# 0 0 2 3 0 5 0 7 8 8 10 7
# 10
# 0 0 0 0 4 4 6 6 8 8
# 8
# 0 0 2 2 2 2 0 7
# 12
# 0 0 2 0 4 5 0 7 7 7 10 10

# 1
# 15
# 0 1 2 3 3 3 3 0 8 9 10 10 9 9 0



    # print(right)
    # rem_left = sorted(left)
    # jr=len(rem_left)-1
    # jl=0
    # rem_right = sorted(right)
    # kr = len(rem_right)-1
    # kl=0
    # leftseen = set()
    # for i in range(idx,-1,-1):

    #     if perm[a[i]-1]!=0 and a[i] and i not in leftseen:
    #         print(i,"here, already taken",rem_left[jr])
    #         leftseen.add(a[i]-1)
    #         perm[a[i]]=rem_left[jr]
    #         jr-=1
    #         print(perm)
    #     if perm[a[i]-1]==0 and a[i] and i not in leftseen:
    #         print(i,"ahem ahem",rem_left[jr])
    #         leftseen.add(a[i]-1)
    #         perm[a[i]-1]=rem_left[jr]
    #         jr-=1
    #         print(perm)


    # print(perm)
    # for i in range(idx+1,n-1):

    #     if perm[a[i]-1]!=0 and a[i] and (a[i]-1) not in rightseen:
    #         print(i,"here, already taken",rem_right[kl],a[i])
    #         rightseen.add(a[i]-1)
    #         perm[a[i]]=rem_right[kl]
    #         print(perm)
    #         kl+=1
    #     elif perm[a[i]-1]==0 and a[i] and (a[i]-1) not in rightseen:
    #         print(i,"nottaken",rem_right[kr])
    #         rightseen.add(a[i]-1)
    #         perm[a[i]-1]=rem_right[kr]
    #         kr-=1
    #         print(perm)


    
    
    # # print(perm)

    

    # for i in range(idx+1,-1,-1):
    #     if perm[i]==0:
    #         perm[i] = rem_left[jl]
    #         jl+=1
    # # print(perm,"******")
    
    # # print(rem_right)
    # for i in range(idx+1,n):
    #     if perm[i]==0:
    #         perm[i] = rem_right[kl]
    #         kl+=1
    # print(perm,"ffffffffffffffffffffffffff")

    
    
        
            
            
def main():
    for i in range(ii()):
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