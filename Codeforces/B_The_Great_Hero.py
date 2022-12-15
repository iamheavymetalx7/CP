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



def lcm(a, b):
    return (a*b)//(math.gcd(a,b))

'''
1480B - The Great Hero
The hero needs ⌈𝑏𝑖/𝐴⌉ attacks to kill the
 𝑖-th monster, and he will obtain 
 ⌈𝑏𝑖/𝐴⌉𝑎𝑖 damage after that.

Suppose the 𝑘-th monster is the 
last monster killed by the hero.
 Then the health value of the hero
  before the last attack is
h(k) = B - summ(ceil(bi/A)).
All monsters can be killed if 
and only if max𝑘{ℎ𝑘}>0. This can 
be checked in 𝑂(𝑛) time.

'''
 
def solve(t):
    A,H,n=map(int, input().split())

    a_at=list(map(int,input().split()))
    b_ht=list(map(int,input().split()))

    damage = sum(a_at[i]*math.ceil(b_ht[i]/A) for i in range(n))

    H=H-damage
    if H>0:
        return "YES"
    
    for i in range(n):
        if H+a_at[i]>0:
            return "YES"
    return "NO"

 
def main():
    t = 1
    if path.exists("/Users/nitishkumar/Documents/Template_Codes/Python/CP/Codeforces/input.txt"):
        sys.stdin = open("/Users/nitishkumar/Documents/Template_Codes/Python/CP/Codeforces/input.txt", 'r')
        sys.stdout = open("/Users/nitishkumar/Documents/Template_Codes/Python/CP/Codeforces/output.txt", 'w')
        start_time = time.time()
        print("\n--- %s seconds ---\n" % (time.time() - start_time))
 
    
    
    sys.setrecursionlimit(10**5)


    t = int(input())
 


    for i in range(t):
        z=solve(i+1)
        print(z)
 
if __name__ == '__main__':
    main()