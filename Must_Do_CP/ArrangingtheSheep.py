'''
https://codeforces.com/blog/entry/90342'''
import sys

import math, collections

sys.stdout = open('/Users/nitishkumar/Documents/Template_Codes/Python/CP_Oct/output.txt','w')
sys.stdin = open('/Users/nitishkumar/Documents/Template_Codes/Python/CP_Oct/input.txt','r')

for t in range(int(input())):
    n=int(input())
    s = str(input())

    def mini_moves(sheep):
        count=0
        ar=[]
        for i in range(n):
            if s[i]=="*":
                ar.append(i)
        print(ar)
        for i in range(len(ar)):
            ar[i]-=i
        print(ar)
        m=len(ar)//2
        res=0
        for i in range(len(ar)):
            res+=abs(ar[m]-ar[i])
        return res


    print(mini_moves(s))


