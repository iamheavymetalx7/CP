# https://codeforces.com/contest/121/submission/185250809
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

# Codeforces Assemble
# Segment Tree - self implementation

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
 
# using decode : https://codeforces.com/blog/entry/83441
si= lambda:str(input().decode())
ii = lambda: int(input().decode())
mii = lambda: map(int, input().decode().split())
lmii = lambda: list(map(int, input().decode().split()))
smii = lambda: list(map(str, input().decode().split()))

i2c = lambda n: chr(ord('a') + n)
c2i = lambda c: ord(c) - ord('a')


# ------------- lazy segment tree ----------------- #

class LazySegmentTree:
    def __init__(self, data, default=0, func=lambda a,b:a+b):
        """initialize the lazy segment tree with data"""
        self._default = default
        self._func = func

        self._len = len(data)
        self._size = _size = 1 << (self._len - 1).bit_length()
        self._lazy = [0] * (2 * _size)

        self.data = [default] * (2 * _size)
        self.data[_size:_size + self._len] = data
        for i in reversed(range(_size)):
            self.data[i] = func(self.data[i + i], self.data[i + i + 1])

    def __len__(self):
        return self._len

    def _push(self, idx):
        """push query on idx to its children"""
        # Let the children know of the queries
        q, self._lazy[idx] = self._lazy[idx], 0

        self._lazy[2 * idx] += q
        self._lazy[2 * idx + 1] += q
        self.data[2 * idx] += q
        self.data[2 * idx + 1] += q

    def _update(self, idx):
        """updates the node idx to know of all queries applied to it via its ancestors"""
        for i in reversed(range(1, idx.bit_length())):
            self._push(idx >> i)

    def _build(self, idx):
        """make the changes to idx be known to its ancestors"""
        idx >>= 1
        while idx:
            self.data[idx] = self._func(self.data[2 * idx], self.data[2 * idx + 1]) + self._lazy[idx]
            idx >>= 1

    def add(self, start, stop, value):
        """lazily add value to [start, stop)"""
        start = start_copy = start + self._size
        stop = stop_copy = stop + self._size
        while start < stop:
            if start & 1:
                self._lazy[start] += value
                self.data[start] += value
                start += 1
            if stop & 1:
                stop -= 1
                self._lazy[stop] += value
                self.data[stop] += value
            start >>= 1
            stop >>= 1

        # Tell all nodes above of the updated area of the updates
        self._build(start_copy)
        self._build(stop_copy - 1)

    def query(self, start, stop, default=0):
        """func of data[start, stop)"""
        start += self._size
        stop += self._size

        # Apply all the lazily stored queries
        self._update(start)
        self._update(stop - 1)

        res = default
        while start < stop:
            if start & 1:
                res = self._func(res, self.data[start])
                start += 1
            if stop & 1:
                stop -= 1
                res = self._func(res, self.data[stop])
            start >>= 1
            stop >>= 1
        return res

    def __repr__(self):
        return "LazySegmentTree({0})".format(self.data)


# -------------------------------------------------- #

#if(os.path.exists('/Users/nitishkumar/Documents/Template_Codes/Python/CP/Codeforces/input.txt')):
#     sys.stdin = open("/Users/nitishkumar/Documents/Template_Codes/Python/CP/Codeforces/input.txt","r") ; sys.stdout = open("/Users/nitishkumar/Documents/Template_Codes/Python/CP/Codeforces/output.txt","w") 
#     start_time = time.time()
#     # print("--- %s seconds ---" % (time.time() - start_time))
# else:
#     
input = io.BytesIO(os.read(0, os.fstat(0).st_size)).readline

lucky_arr =[4, 7, 44, 47, 74, 77, 444, 447, 474, 477, 744, 747, 774, 777, 4444, 4447, 4474, 4477, 4744, 4747, 4774, 4777, 7444, 7447, 7474, 7477, 7744, 7747, 7774, 7777, 44444, 44447, 44474, 44477, 44744, 44747, 44774, 44777, 47444, 47447, 47474, 47477, 47744, 47747, 47774, 47777, 74444, 74447, 74474, 74477, 74744, 74747, 74774, 74777, 77444, 77447, 77474, 77477, 77744, 77747, 77774, 77777]
lucky=[0]*(10**5)

for l in lucky_arr:
    lucky[l]=1

# print(lucky)

n,m=lmii()
# n - number of elts in arr
# m - number of operations
arr=lmii()

maskLucky =[0]*n

for i in range(n):
    maskLucky[i]=lucky[arr[i]]

# print(maskLucky)

lst = LazySegmentTree(maskLucky)

# print(lst)

for _ in range(m):
    q=smii()
    if q[0]=="count":
        l,r=int(q[1]),int(q[2])
        # print("count",l,r)

        l-=1
        r-=1
        ans = lst.query(l,r+1)
        print(ans)

    elif q[0]=="add":
        l,r=int(q[1]),int(q[2])
        val=int(q[3])
        # print(val,"val")
        l-=1
        r-=1

        for j in range(l,r+1):
            if lucky[arr[j]]:
                lst.add(j,j+1,-1)

            arr[j]+=val

            if lucky[arr[j]]:
                lst.add(j,j+1,1) 



# def main():
#     t = 1
#     if path.exists("/Users/nitishkumar/Documents/Template_Codes/Python/CP/Codeforces/input.txt"):
#         sys.stdin = open("/Users/nitishkumar/Documents/Template_Codes/Python/CP/Codeforces/input.txt", 'r')
#         sys.stdout = open("/Users/nitishkumar/Documents/Template_Codes/Python/CP/Codeforces/output.txt", 'w')
#         start_time = time.time()
#         print("--- %s seconds ---" % (time.time() - start_time))
 
 
#     sys.setrecursionlimit(10**5)
 
#     t = int(input())
 
#     for i in range(t):
#         solve(i+1)
 
 
# if __name__ == '__main__':
#     main()
    
 


