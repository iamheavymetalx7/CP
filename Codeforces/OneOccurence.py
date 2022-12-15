'''
https://codeforces.com/contest/1000/problem/F
'''
from collections import Counter
import sys
sys.stdout = open('output.txt','w')
sys.stdin = open('input.txt','r')
import math, itertools, collections

n = int(input())
arr = [*map(int, input().split())]

for testcase in range(int(input())):
    l,r = map(int, input().split())
    print(arr, l,r)

    c_ = Counter(arr[l:r+1])
    
    for i,k in c_.items():
        if c_[i]==1:
            print(i)
    print(0)
        
