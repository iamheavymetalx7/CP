from bisect import *
from heapq import *
from collections import defaultdict,Counter
import sys
input = lambda: sys.stdin.readline().rstrip("\r\n")
from os import path
if(path.exists('input.txt')):
    sys.stdin = open("input.txt","r")
    sys.stdout = open("output.txt","w")

n=int(input())

arr =[]
for _ in range(n):
    arr.append(list(map(int, input().split())))

## n<=16, so possibly try all possible cases is the only way out
# from functools import cache
pre =[0 for _ in range(1<<n)]

for mask in range(1<<n):
    for i in range(n):
        if mask&(1<<i):
            for j in range(i+1,n):
                if mask&(1<<j):
                    pre[mask]+=arr[i][j]
# @cache
def recur(i,not_taken,score_so_far,mask,group):
    if i==len(not_taken):
        dp[mask] = max(dp[mask],score_so_far+pre[group])
        return
    
    recur(i+1,not_taken,score_so_far,mask,group)
    recur(i+1,not_taken,score_so_far,mask^(1<<not_taken[i]),group^(1<<not_taken[i]))


inf = int(1e18)


dp =[-inf for _ in range(1<<n)]

dp[0]=0
for mask in range(1<<n):
    not_taken =[]
    for i in range(n):
        if not (mask&(1<<i)):
            not_taken.append(i)
    print(mask, not_taken)
    recur(0,not_taken,dp[mask],mask,0)

                
print(dp[(1<<n)-1])
