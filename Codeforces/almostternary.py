##https://codeforces.com/problemset/problem/1699/B

import sys

sys.stdout = open('/Users/nitishkumar/Documents/Template_Codes/Python/CP_Oct/output.txt','w')
sys.stdin = open('/Users/nitishkumar/Documents/Template_Codes/Python/CP_Oct/input.txt','r')


for testcase in range(int(input())):
    n,m = list(map(int,input().split()))

    ans=[[1,0,0,1],[0,1,1,0],[0,1,1,0],[1,0,0,1]]

    for i in range(n):
        for j in range(m):
            print(ans[i%4][j%4],end=" ")
        print()