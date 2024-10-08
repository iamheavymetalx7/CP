#bisect.bisect_left(a, x, lo=0, hi=len(a)) is the analog of std::lower_bound()
#bisect.bisect_right(a, x, lo=0, hi=len(a)) is the analog of std::upper_bound()
#from heapq import heappop,heappush,heapify #heappop(hq), heapify(list)
#from collections import deque as dq #deque  e.g. myqueue=dq(list)
#append/appendleft/appendright/pop/popleft
#from bisect import bisect as bis #a=[1,3,4,6,7,8] #bis(a,5)-->3
#import bisect #bisect.bisect_left(a,4)-->2 #bisect.bisect(a,4)-->3
#import statistics as stat  # stat.median(a), mode, mean
#from itertools import permutations(p,r)#combinations(p,r)
#combinations(p,r) gives r-length tuples #combinations_with_replacement
#every element can be repeated
        
#Note direct assignment to check somethings doesnt work always
#say there exists s (list) then ss=s and if we edit ss, it edits s as well
#always try to use ss=s.copy() if u wish to make changes to ss and not reflect them in s.
#For example: see **1379A - Acacius and String** for reference
    
import sys, threading, os, io 
import math
import time
from os import path
from collections import defaultdict, Counter, deque
from bisect import *
from string import ascii_lowercase
from functools import cmp_to_key
import heapq
from bisect import bisect_left as lower_bound
from bisect import bisect_right as upper_bound
from io import BytesIO, IOBase								
# # # # # # # # # # # # # # # #
#       JAI SHREE RAM         #
# # # # # # # # # # # # # # # #
 
 
def lcm(a, b):
    return (a*b)//(math.gcd(a,b))
 
 
input = lambda: sys.stdin.readline().rstrip()
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
    
    
if(os.path.exists("/Users/nitishkumar/Documents/Template_Codes/Python/CP/Codeforces/input.txt")):
    sys.stdin = open("/Users/nitishkumar/Documents/Template_Codes/Python/CP/Codeforces/input.txt", 'r')
    sys.stdout = open("/Users/nitishkumar/Documents/Template_Codes/Python/CP/Codeforces/output.txt", 'w') 
else:
    input = io.BytesIO(os.read(0, os.fstat(0).st_size)).readline
    
    
def solve():
    n=ii()  # matches played
    a=ii()  # goals scores
    b=ii()  # goals conceded
    if n==1 and a==b:
        print(1)
        print(str(a)+":"+str(b))
        return
    if n==1:
        print(0)
        print(str(a)+":"+str(b))
        return
    if a+b<n:
        print(n-(a+b))
        ar=[]

        for _ in range(n-(a+b)):
            ar.append((0,0))

        for i in range(a):
            ar.append((1,0))
        for j in range(b):
            ar.append((0,1))
        
        for ele in ar:
            print(str(ele[0])+":"+str(ele[1]))
        return
    
    print(0)
    ar=[]
    if a==0:
        for i in range(n-1):
            ar.append((0,1))
        ar.append((0,b-(n-1)))
        for ele in ar:
            print(str(ele[0])+":"+str(ele[1]))
        return
    elif b==0:
        for i in range(n-1):
            ar.append((1,0))
        ar.append((a-(n-1),0))
        for ele in ar:
            print(str(ele[0])+":"+str(ele[1]))
        return
    else:
        # print("we are here")
        ar.append([1,0])
        a-=1
        b-=1
        ar.append([0,1])
        # print(a,b)
        i=0
        while a>0 and b>0 and i<n-2:
            # print(i,"here...")
            ar.append([1,0])
            a-=1
            i+=1
            if i<n-2:
                ar.append([0,1])
                b-=1
            i+=1
        while i<n-2:
            if a>0:
                ar.append([1,0])
                a-=1
                i+=1
            elif b>0:
                ar.append([0,1])
                b-=1
                i+=1
        if b>0:
            ar[1][1]+=b
        if a>0:
            ar[0][0]+=a

        # print(len(ar))
        for ele in ar:
            print(str(ele[0])+":"+str(ele[1]))
        return
        


    
    
solve()