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

## https://codeforces.com/contest/1749/submission/177156617
## By xxh1999, contest: Educational Codeforces Round 138 (Rated for Div. 2), problem: (C) Number Game, Accepted, #, Copy
 
def lcm(a, b):
    return (a*b)//(math.gcd(a,b))
 
 
ii = lambda: int(input())
mii = lambda: map(int, input().split())
lmii = lambda: list(map(int, input().split()))
i2c = lambda n: chr(ord('a') + n)
c2i = lambda c: ord(c) - ord('a')
    
    
def solve(t):
    n=ii()
    l=lmii()
    ans=0
    low,high=0,n
    l.sort()

    ## here we are checking whether we can work with k
    ## so that alice ends up winning
    while low<=high:
        mid=(high+low)//2
        deq = deque(l)
        k=mid
        while deq:
            while deq and deq[-1]>k:
                deq.pop()
            if not deq:
                break
            deq.pop()
            k-=1    ##important to decrement k here!!

            if not deq:
                break
            deq.popleft()

        if k==0:
            ans=mid
            low=mid+1
        else:
            high=mid-1
    print(ans)
    
    
def main():
    t = 1
    if path.exists("/Users/nitishkumar/Documents/Template_Codes/Python/CP/Codeforces/input.txt"):
        sys.stdin = open("/Users/nitishkumar/Documents/Template_Codes/Python/CP/Codeforces/input.txt", 'r')
        sys.stdout = open("/Users/nitishkumar/Documents/Template_Codes/Python/CP/Codeforces/output.txt", 'w')
        start_time = time.time()
        print("--- %s seconds ---" % (time.time() - start_time))
 
 
    sys.setrecursionlimit(10**5)
 
    t = int(input())
 
    for i in range(t):
        solve(i+1)
 
 
if __name__ == '__main__':
    main()