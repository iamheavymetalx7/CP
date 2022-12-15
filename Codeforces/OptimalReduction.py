#https://codeforces.com/contest/1713/problem/B

## except the end points there should be no point
## in the array where get that its left side is greater and
## also its right side is greater!

from collections import deque
import sys

sys.stdout = open('/Users/nitishkumar/Documents/Template_Codes/Python/CP/Codeforces/output.txt','w')
sys.stdin = open('/Users/nitishkumar/Documents/Template_Codes/Python/CP/Codeforces/input.txt','r')

for testcase in range(int(input())):
    n=int(input())
    A=list(map(int, input().split()))

    if n==1:
        print("YES")
        continue
    i=1

    while i<n and A[i]>=A[i-1]:
        i=i+1
    while i+1<n and A[i]>=A[i+1]:
        i=i+1
    
    if i>=n-1:
        print("YES")
    else:
        print("NO")
