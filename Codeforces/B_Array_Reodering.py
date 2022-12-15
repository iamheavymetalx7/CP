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
'''
If the value of 𝑎𝑖 is even,
then gcd(𝑎𝑖,2𝑎𝑗) at least 2, regardless of 
the value of 𝑎𝑗. Therefore, we can put all the
even values before the odd ones (it does not 
matter in what order). Now it remains to 
arrange the odd values. In fact, their order
is not important, because gcd(𝑎𝑖,2𝑎𝑗)=gcd(𝑎𝑖,𝑎𝑗)
(for odd 𝑎𝑖 and 𝑎𝑗). This means that each pair 
will be considered exactly 1 time, regardless
of the order of the odd elements.
'''
 
def solve(t):
    n=int(input())
    a=list(map(int, input().split()))


    dic=defaultdict(list)

    for i in range(n):
        dic[a[i]%2].append(a[i])

    arr=dic[0]
    arr+=dic[1]

    ans=0

    for i in range(n):
        for j in range(i+1,n):
            if math.gcd(arr[i],2*arr[j])>1:
                ans+=1


    print(ans)

    
def main():
    t = 1
    if path.exists("/Users/nitishkumar/Documents/Template_Codes/Python/CP/Codeforces/input.txt"):
        sys.stdin = open("/Users/nitishkumar/Documents/Template_Codes/Python/CP/Codeforces/input.txt", 'r')
        sys.stdout = open("/Users/nitishkumar/Documents/Template_Codes/Python/CP/Codeforces/output.txt", 'w')
    sys.setrecursionlimit(10**5)
 
    t = int(input())
 
    for i in range(t):
        solve(i+1)
 
 
if __name__ == '__main__':
    main()