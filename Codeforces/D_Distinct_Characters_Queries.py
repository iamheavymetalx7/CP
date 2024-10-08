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

import operator
 
   ####    ##       ####             ## ##   ###  ##  ### ##   ### ###  ### ###           ### ##     ##     ##   ##  
    ##      ##       ##             ##   ##   ##  ##   ##  ##   ##  ##   ##  ##            ##  ##     ##     ## ##   
    ##    ## ##      ##             ####      ##  ##   ##  ##   ##       ##                ##  ##   ## ##   # ### #  
    ##    ##  ##     ##              #####    ## ###   ## ##    ## ##    ## ##             ## ##    ##  ##  ## # ##  
##  ##    ## ###     ##                 ###   ##  ##   ## ##    ##       ##                ## ##    ## ###  ##   ##  
##  ##    ##  ##     ##             ##   ##   ##  ##   ##  ##   ##  ##   ##  ##            ##  ##   ##  ##  ##   ##  
 ## #    ###  ##    ####             ## ##   ###  ##  #### ##  ### ###  ### ###           #### ##  ###  ##  ##   ##  
                                                                                                                     

 
# PyRival version 

# https://codeforces.com/contest/1234/submission/61632034
def lcm(a, b):
    return (a*b)//(math.gcd(a,b))
 
 
si= lambda:str(input())
ii = lambda: int(input())
mii = lambda: map(int, input().split())
sii= lambda: map(str,input().split())
lmii = lambda: list(map(int, input().split()))
i2c = lambda n: chr(ord('a') + n)
c2i = lambda c: ord(c) - ord('a')


# # # # # # # Segment Tree # # # # # # # #

class SegmentTree:
    def __init__(self, data, default=0, func=max):
        """initialize the segment tree with data"""
        self._default = default
        self._func = func
        self._len = len(data)
        self._size = _size = 1 << (self._len - 1).bit_length()

        self.data = [default] * (2 * _size)
        self.data[_size:_size + self._len] = data
        for i in reversed(range(_size)):
            self.data[i] = func(self.data[i + i], self.data[i + i + 1])

    def __delitem__(self, idx):
        self[idx] = self._default

    def __getitem__(self, idx):
        return self.data[idx + self._size]

    def __setitem__(self, idx, value):
        idx += self._size
        self.data[idx] = value
        idx >>= 1
        while idx:
            self.data[idx] = self._func(self.data[2 * idx], self.data[2 * idx + 1])
            idx >>= 1

    def __len__(self):
        return self._len

    def query(self, start, stop):
        """func of data[start, stop)"""
        start += self._size
        stop += self._size

        res_left = res_right = self._default
        while start < stop:
            if start & 1:
                res_left = self._func(res_left, self.data[start])
                start += 1
            if stop & 1:
                stop -= 1
                res_right = self._func(self.data[stop], res_right)
            start >>= 1
            stop >>= 1

        return self._func(res_left, res_right)

    def __repr__(self):
        return "SegmentTree({0})".format(self.data)

# # # # # # # # # # # # # # # # # # # # # #

def CountSetBits(n):
    count=0

    while n:
        if n & 1:
            count+=1
        n>>=1

    return count

def solve():
    s = [1 << (ord(c) - ord('a')) for c in input()]
    
    seg = SegmentTree(s, func = operator.or_)

    q=ii()

    for _ in range(q):
        t,a,b=sii()

        if t=="1":
            # print(1<<(ord(b)-ord('a')),"type ==1")
            seg[int(a)-1]=1<<(ord(b)-ord('a'))
        else:
            print(bin(seg.query(int(a)-1,int(b))).count('1'))
            # or we can do this also:
            # print(CountSetBits(seg.query(int(a)-1,int(b))))


## Another solution : different version of segment tree:

# https://codeforces.com/contest/1234/submission/147497682 
# Note: the way of updating the segment tree is same, it is done under modify_seg_tree
#       and query segment tree does the same thing which we have done above!!

'''import sys
def build_seg_tree(n, s): 
    tree = [0 for _ in range(2*n)] 
    base = ord('a')
    for i in range(n, 2*n):
        tree[i] = 1 << ( ord(s[i-n]) - base )
    for i in range(n-1, 0, -1):
        tree[i] = tree[2*i] | tree[(2*i)+1]
    return tree
 
def modify_seg_tree(tree, pos, char): 
    n = len(tree) >> 1
    pos += n 
    base = ord('a')
    tree[pos] = 1 << ( ord(char) - base ) 
    while pos > 1:
        pos >>= 1
        tree[pos] = tree[2*pos] | tree[(2*pos)+1]
    return
 
def query_seg_tree(tree, lptr, rptr): 
    res = 0
    n = len(tree) >> 1
    lptr += n
    rptr += n
    while lptr < rptr:
        if lptr % 2 == 1: 
            res |= tree[lptr] 
            lptr += 1
        if rptr % 2 == 1:
            rptr -= 1
            res |= tree[rptr] 
        lptr >>= 1
        rptr >>= 1
    return bin(res).count('1')
 
def main():
    s = sys.stdin.readline().rstrip()
    tree = build_seg_tree(len(s), s)
    q = int(sys.stdin.readline())
    for i in range(q):
        type, pl, cr = sys.stdin.readline().split()
        if type == '1':
            modify_seg_tree(tree, int(pl)-1, cr)
        else:
            print(query_seg_tree(tree, int(pl)-1, int(cr)))
    return
main()

'''
    
    
def main():
    t = 1
    if path.exists("/Users/nitishkumar/Documents/Template_Codes/Python/CP/Codeforces/input.txt"):
        sys.stdin = open("/Users/nitishkumar/Documents/Template_Codes/Python/CP/Codeforces/input.txt", 'r')
        sys.stdout = open("/Users/nitishkumar/Documents/Template_Codes/Python/CP/Codeforces/output.txt", 'w')
        start_time = time.time()
        print("--- %s seconds ---" % (time.time() - start_time))
 
    solve()
 
if __name__ == '__main__':
    main()
    
 


