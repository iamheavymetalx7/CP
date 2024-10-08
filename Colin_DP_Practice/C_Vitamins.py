# /**
# * author:Hisoka-TheMagician
# * created: 10/05/2023 17:56 Chennai, India
# **/
        




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
    
    
# if(os.path.exists("/Users/nitishkumar/Documents/Template_Codes/Python/CP/Codeforces/input.txt")):
#     sys.stdin = open("/Users/nitishkumar/Documents/Template_Codes/Python/CP/Codeforces/input.txt", 'r')
#     sys.stdout = open("/Users/nitishkumar/Documents/Template_Codes/Python/CP/Codeforces/output.txt", 'w') 
# else:
#     input = io.BytesIO(os.read(0, os.fstat(0).st_size)).readline
    
def solve():
    n=ii()
    inf = int(1e17)

    f=[[0]*(8) for _ in range(n+1)]

    # print(f)
    for i in range(n+1):
        for j in range(8):
            f[i][j] = inf
    
    f[0][0] = 0
    ans=inf

    for i in range(n):
        cost,s=input().split()
        cost=int(cost)

        string_mask=0 


        for pos in range(3):
            c=ord('C')-pos
            have=0

            for d in s:
                if c==ord(d):
                    have=1
            
            if have:
                string_mask+=1<<pos ## 2^ pos

        for mask in range(8):
            # print(i,mask)
            f[i+1][mask]=min(f[i+1][mask], f[i][mask])
            f[i+1][mask | string_mask]=min(f[i+1][mask|string_mask], f[i][mask]+cost)
            

    ans=f[n][7]
    if ans==inf:
        ans=-1
    print(ans)
# def solve():

    # n=ii()
    # arr=[[10**9] for i in range(7)]

    # # print(arr)

    # seen=set()

    # for _ in  range(n):
    #     p,s=input().split()
    #     for c in s:
    #         seen.add(c)
    #     p=int(p)
    #     s=sorted(s)

    #     s=''.join(s)
    #     # print(p,s)
    #     if s=="A":
    #         arr[0].append(p)
    #     elif s=="B":
    #         arr[1].append(p)
    #     elif s=="C":
    #         arr[2].append(p)
    #     elif s=="AB":
    #         arr[3].append(p)
    #     elif s=="BC":
    #         arr[4].append(p)
    #     elif s=="AC":
    #         arr[5].append(p)
    #     elif s=="ABC":
    #         arr[6].append(p)

    # if len(seen)!=3:print(-1); return
    # for ele in arr:
    #     ele.sort()
    
    # # print(arr)
    
    # ans=min(arr[0][0]+arr[1][0]+arr[2][0],arr[3][0]+arr[2][0],arr[4][0]+arr[0][0],arr[5][0]+arr[1][0],arr[6][0],arr[3][0]+arr[4][0],arr[4][0]+arr[5][0],arr[5][0]+arr[3][0])

    # print(ans)

    
    
    
    
xxx=1
for _ in range(xxx):
    solve()