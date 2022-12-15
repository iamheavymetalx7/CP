import sys, threading
import math
from os import path
from collections import defaultdict, Counter, deque
from bisect import *
from string import ascii_lowercase
from functools import cmp_to_key
import heapq
 
'''
Chandan now wonders about minimum 
number of operations needed to 
convert a rank list of size n
 with sum of its element equal 
 to s in to an ideal rank list. 
 Please help Chandan find this 
 minimum number of operations 
 needed to create an ideal rank list.
'''
def lcm(a, b):
    return (a*b)//(math.gcd(a,b))
 
 
def solve(t):
    n,s=map(int, input().split())
    isum=int((n*(n+1))/2)
    cnt=0
    while isum>s:
        isum-=n
        n=n-1
        s-=1
        cnt+=1

    return cnt
    


 
 
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