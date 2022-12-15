import sys, threading
import math
from os import path
from collections import defaultdict, Counter, deque
from bisect import *
from string import ascii_lowercase
from functools import cmp_to_key
import heapq
 
 
def lcm(a, b):
    return (a*b)//(math.gcd(a,b))
 
 
def solve(t):
    N,X=map(int,input().split())
    A=list(map(int,input().split()))
    ans = max(N, math.ceil(X/min(A)))
    return ans
 
def main():
    t = 1
    if path.exists("/Users/nitishkumar/Documents/Template_Codes/Python/CP/Codechef/input.txt"):
        sys.stdin = open("/Users/nitishkumar/Documents/Template_Codes/Python/CP/Codechef/input.txt", 'r')
        sys.stdout = open("/Users/nitishkumar/Documents/Template_Codes/Python/CP/Codechef/output.txt", 'w')
    sys.setrecursionlimit(10**5)
 
    t = int(input())

 
    for i in range(t):
        z= solve(i+1)
        print(z)

 
 
if __name__ == '__main__':
    main() 