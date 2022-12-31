#bisect.bisect_left(a, x, lo=0, hi=len(a)) is the analog of std::lower_bound()
#bisect.bisect_right(a, x, lo=0, hi=len(a)) is the analog of std::upper_bound()
#from heapq import heappop,heappush,heapify #heappop(hq), heapify(list)
#from collections import deque as dq #deque  e.g. myqueue=dq(list)
#append/appendleft/appendright/pop/popleft
#from bisect import bisect as bis #a=[1,3,4,6,7,8] #bis(a,5)-->3
#import bisect #bisect.bisect_left(a,4)-->2 #bisect.bisect(a,4)-->3
#import statistics as stat  # stat.median(a), mode, mean
#from itertools import permutations(p,r)#combinations(p,r)
#combinations(p,r) gives r-length tuples #combinations_with_replacement
#every element can be repeated
        
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
    
mod=10**97
def solve(t):
    n=ii()

    dire =[[0,1],[1,0]]

    if n<=10**6:
        ans=1
        init=[1,1]
        flag=0
        while init!=[n,n]:  ##greater than 10^9
            if flag%2==0:
                init[1]+=dire[0][1]
                ans+=init[0]*init[1]
                flag+=1
            else:
                init[0]+=dire[1][0]
                ans+=init[0]*init[1]
                flag+=1
    elif 10**6<n<=10**7:
        ans=666667166666500000
        flag=1999998
        init=[10**6,10**6]
        while init!=[n,n]:  ##greater than 10^9
            if flag%2==0:
                init[1]+=dire[0][1]
                ans+=init[0]*init[1]
                flag+=1
            else:
                init[0]+=dire[1][0]
                ans+=init[0]*init[1]
                flag+=1
    elif 10**7<n<=10**8:
        ans=666666716666665000000
        flag=19999998
        init=[10**7,10**7]

        while init!=[n,n]:  ##greater than 10^9
            if flag%2==0:
                init[1]+=dire[0][1]
                ans+=init[0]*init[1]
                flag+=1
            else:
                init[0]+=dire[1][0]
                ans+=init[0]*init[1]
                flag+=1
    elif 10**8<n<=10**9:
        ans=666666671666666650000000

        flag=199999998
        init=[10**8,10**8]

        while init!=[n,n]:  ##greater than 10^9
            if flag%2==0:
                init[1]+=dire[0][1]
                ans+=init[0]*init[1]
                flag+=1
            else:
                init[0]+=dire[1][0]
                ans+=init[0]*init[1]
                flag+=1


   
    ans=ans*2022
    print(ans%mod)        



 
    
    
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
    
 


