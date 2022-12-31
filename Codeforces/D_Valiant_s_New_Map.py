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
        
import sys, threading
import math
import time
from os import path
from collections import defaultdict, Counter, deque
from bisect import *
from string import ascii_lowercase
from functools import cmp_to_key
import heapq
 
 
# # # # # # # # # # # # # # # #
#       JAI SHREE RAM         #
# # # # # # # # # # # # # # # #
 


# Codeforces Assemble 
# Binary search

# https://leetcode.com/problems/maximal-square/solution/
def lcm(a, b):
    return (a*b)//(math.gcd(a,b))
 
 
si= lambda:str(input())
ii = lambda: int(input())
mii = lambda: map(int, input().split())
lmii = lambda: list(map(int, input().split()))
i2c = lambda n: chr(ord('a') + n)
c2i = lambda c: ord(c) - ord('a')

def maxValcheck(arr,mid):
    n=len(arr)
    m=len(arr[0])
    dp=[[0]*m for j in range(n)]
    for i in range(n):
        for j in range(m):
            if arr[i][j]>=mid:
                dp[i][j]=1

                if i>0 and j>0:
                    dp[i][j]+=min(dp[i-1][j],dp[i-1][j-1],dp[i][j-1])
                if dp[i][j]==mid:
                    return True
    return False

    
    
def solve(t):
    n,m=mii()
    arr=[]
    ans=1
    for i in range(n):
        arr.append(lmii())

    low,high=1,min(m,n)

    while low<=high:
        mid=(low+high)//2
    

        if maxValcheck(arr,mid):
            ans = mid
            low=mid+1
        else:
            high=mid-1
    print(ans)
    
def main():

 
    sys.setrecursionlimit(10**5)
 
    t = int(input())
 
    for i in range(t):
        solve(i+1)
 
 
if __name__ == '__main__':
    main()
    
 


