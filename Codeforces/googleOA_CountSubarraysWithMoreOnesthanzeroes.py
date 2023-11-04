from bisect import *
from heapq import *
from collections import defaultdict,Counter
import sys
input = lambda: sys.stdin.readline().rstrip("\r\n")
from os import path
if(path.exists('input.txt')):
    sys.stdin = open("input.txt","r")
    sys.stdout = open("output.txt","w")

class BIT:
    def __init__(self,n):
        self.sums =[0]*(n+1)
    
    def update(self,idx,val):
        while idx<len(self.sums):
            self.sums[idx]+=val
            idx+=(idx&(-idx))
    
    def query(self,idx):
        s=0
        while idx>0:
            s+=self.sums[idx]
            idx-=(idx&(-idx))
        return s

def SubarraysWithMoreOnesThanZeroes(nums):
    n = len(nums)
    curr =0
    offset = int(1e5)+1
    Fenwick = BIT(2*offset+10)
    ans=0
    MOD = int(1e9)+7
    def calc_idx(x):
        return x+offset

    Fenwick.update(calc_idx(0),1)

    for i in range(n):
        if nums[i]==1:
            curr+=1
        else:
            curr-=1

        ans= ans + Fenwick.query(calc_idx(curr)-1)
        Fenwick.update(calc_idx(curr),1)
    
    return (ans)

val = SubarraysWithMoreOnesThanZeroes([0,1,1,1,1,0,0,1,1,1])
print(val)

val = SubarraysWithMoreOnesThanZeroes([0,0,0,0,0,1,0,1,0,0])
print(val)

