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

First of all, let's think about how we
should rearrange the two strings
in such a way that 𝑎<𝑏 (if that
is ever possible). It's always
optimal to arrange 𝑎's characters
increasingly in lexicographic order
and 𝑏's characters decreasingly.

Since initially both 𝑎 and 𝑏 
contain a character "a", the 
first time 𝑏 receives any other
letter than "a" the answer will 
always be "YES", because that 
character will always be 
lexicographically larger than 𝑎's 
first character which should be "a".

In the other case, we know that 𝑏 
doesn't have any other characters 
than "a", so we can compare the 
string 𝑎 with multiple "a" characters 
and we know that 𝑎 will be smaller if 
and only if it's only formed of "a"s 
and has a smaller size than 𝑏.

'''
 
def lcm(a, b):
    return (a*b)//(math.gcd(a,b))
 
'''
- 1 𝑘 𝑥  — Append the string 𝑥 exactly 𝑘 
times at the end of string 𝑠.
- 2 𝑘 𝑥  — Append the string 𝑥 exactly 𝑘
 times at the end of string 𝑡.
''' 

def solve(t):
    s,t="a","a"
    otherA = False
    otherB = False
    n=int(input())

    cntA=0
    cntB=0


    for i in range(n):
        d,k,x=input().split()
        d=int(d)
        k=int(k)
        for c in x:
            if d==1:
                if c!='a':
                    otherA=1
                else:
                    cntA+=k
            else:
                if c!='a':
                    otherB=1
                else:
                    cntB+=k
        if otherB:
            print("YES")
        elif not otherA and cntA<cntB:
            print("YES")
        else:
            print("NO")



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