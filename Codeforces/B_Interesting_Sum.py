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

'''

Obviously, answer does not exceed 𝑚𝑎𝑥1+𝑚𝑎𝑥2−𝑚𝑖𝑛1−𝑚𝑖𝑛2, 
where 𝑚𝑎𝑥1,𝑚𝑎𝑥2 are two maximum values in the array, and 
𝑚𝑖𝑛1,𝑚𝑖𝑛2 are two minimum values. Let's find a segment, 
such as this is true. For that we will look at all positions 
containing 𝑚𝑎𝑥1 or 𝑚𝑎𝑥2 (𝑆1) and all positions containing 
𝑚𝑖𝑛1 or 𝑚𝑖𝑛2 (𝑆2). After that we choose a pair 𝑙∈𝑆1, 𝑟∈𝑆2, 
such as 𝑎𝑏𝑠(𝑟−𝑙) is minimum possible. Complexity: 𝑂(𝑛log𝑛)

'''
 
def lcm(a, b):
    return (a*b)//(math.gcd(a,b))
 
 
si= lambda:str(input())
ii = lambda: int(input())
mii = lambda: map(int, input().split())
lmii = lambda: list(map(int, input().split()))
i2c = lambda n: chr(ord('a') + n)
c2i = lambda c: ord(c) - ord('a')
    
    
def solve(t):
    n=ii()
    arr=lmii()

    arr.sort()
    
    print(arr[-1] + arr[-2] - arr[0] - arr[1])

    
    
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