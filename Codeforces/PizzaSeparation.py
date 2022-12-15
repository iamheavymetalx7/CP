#https://codeforces.com/contest/895/problem/A?f0a28=2

##important observation: continuous sectors 

from collections import deque
import sys

sys.stdout = open('/Users/nitishkumar/Documents/Template_Codes/Python/CP/Codeforces/output.txt','w')
sys.stdin = open('/Users/nitishkumar/Documents/Template_Codes/Python/CP/Codeforces/input.txt','r')

n=int(input())

A=list(map(int,input().split()))

def angle_diff(x):
    return 2*abs(x-180)

mini=360
total=0
l,r=0,0
while r<n:
    total+=A[r]
    r=r+1

    while total>=180:
        mini=min(mini,angle_diff(total))
        total-=A[l]
        l=l+1
    mini=min(mini,angle_diff(total))

print(mini)


