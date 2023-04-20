'''
. Obviously, for b>=0
, you should delete the characters one by one so that k=n
. Now b<0
 and you have to delete the string in the minimum number of operations. Let the string s
 consist of m
 blocks of zeros and ones, then math.floor(m/2)+1
 is the minimum number of operations for which the entire string can be deleted

'''
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
    n,a,b=mii()
    t=si()
    # print(t)
    ans=0

    if b>=0:
        print(n*a+n*b)
        return
    
    c=1
    for i in range(1,n):
        if t[i]!=t[i-1]:
            c+=1
        
    m=c//2 +1

    print(n*a+b*m)






                



    
    
    
    
t=ii()
for _ in range(t):
    solve()