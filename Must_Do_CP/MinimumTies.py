'''
https://codeforces.com/problemset/problem/1487/C
'''

import sys

sys.stdin=open('/Users/nitishkumar/Documents/Template_Codes/Python/CP_Oct/input.txt','r')
sys.stdout=open('/Users/nitishkumar/Documents/Template_Codes/Python/CP_Oct/output.txt','w')

for test in range(int(input())):
    n=int(input())

    if n%2==1:
        for i in range(n):
            for j in range(i+1,n):
                if j-i<=n/2:
                    print(1,end=" ")
                else:
                    print(-1,end=" ")
        print(" ")

    else:
        for i in range(n):
            for j in range(i+1,n):
                if j-i<n/2:
                    print(1,end=" ")
                elif j-i==n//2:
                    print(0,end=" ")
                else:
                    print(-1,end=" ")
        print(" ")