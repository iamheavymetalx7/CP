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
 
## first we generate all the prime until 10^5
p=[1]*(pow(10,5)+1)
for i in range(2,pow(10,5)+1):
    if p[i]==1:
        for j in range(i*i, pow(10,5)+1, i):
            p[j]=0

## now we store all the primes in arr
pr =[]
for i in range(2,pow(10,5)+1):
    if p[i]==1:
        pr.append(i)




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


    cnt=0
    for i in range(n):
        if arr[i]%2==0:
            cnt+=1
    if cnt>1:
        return "YES"

    pl=len(pr)
    map=defaultdict(int)


    j=0
    for i in range(n):
        for j in range(pl):
            if pr[j]*pr[j]>arr[i]:
                break
            if arr[i]%pr[j]==0:
                if map[pr[j]]:
                    return "YES"

                while arr[i]%pr[j]==0:
                    arr[i]=arr[i]//pr[j]
                    map[pr[j]]+=1


        if arr[i]>1:
            if map[arr[i]]:
                return "YES"
            map[arr[i]]+=1
    return "NO"

        







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
        z = solve(i+1)
        print(z)
if __name__ == '__main__':
    main()