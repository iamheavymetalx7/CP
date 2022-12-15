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
 
 
si= lambda:str(input())
ii = lambda: int(input())
mii = lambda: map(int, input().split())
lmii = lambda: list(map(int, input().split()))
i2c = lambda n: chr(ord('a') + n)
c2i = lambda c: ord(c) - ord('a')


Prime = [0] * 10000000
for i in range(3, 10000000, 2) :
    if Prime[i] == 0 :
        j = 3 ; Prime[i] = i
        while i*j <= 10000000 :
            if not Prime[i*j] : Prime[i*j] = i
            j += 2    
    
def solve(t):
    a,b=mii()

    if math.gcd(a,b)>1:
        print(0)
    elif b-a==1:
        print(-1)
    elif (b-a)%2==0:
        print(1)
    else:
        Ans = int(1e7)
        c = b-a

        while c>1:
            d=Prime[c]
            Ans=min(Ans,d-a%d)
            c//=d
        print(Ans)

    # x1=pow(10,9)

    # diff = int(y-x)

    # if diff==0:
    #     if x==1:
    #         return 1
    #     else:
    #         return 0 
    # elif diff==1:
    #     return -1
 
   

    # while diff>1:
    #     j=p[diff]

    #     if x%j==0:
    #         x1=x
    #     else:
    #         x1=min(x1,int(x/j + 1)*j)

    #     while diff%j==0:
    #         diff//=j
    # return x1-x

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