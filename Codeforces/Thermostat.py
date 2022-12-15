## https://codeforces.com/contest/1759/problem/C

import sys

sys.stdout = open('/Users/nitishkumar/Documents/Template_Codes/Python/CP_Oct/output.txt','w')
sys.stdin = open('/Users/nitishkumar/Documents/Template_Codes/Python/CP_Oct/input.txt','r')


for testcase in range(int(input())):
    l,r,x=map(int,input().split())
    a,b=map(int,input().split())

    if a==b:
        print(0)
    
    ## [l------a-----b-----r]
    if a<b:
        if (b-a)>=x:
            print(1)
        elif (r-b>=x): #a->r->b
            print(2)
        elif (a-l)>=x: #a->l->b
            print(2)
        elif r-a>=x and b-l>=x: #a->r->l->b
            print(3)
        else:
            print(-1)
    
    ##[l-----b------a-----r]
    elif a>b:
        if a-b>=x:
            print(1)
        elif (b-l>=x): #a->l->b
            print(2)
        elif (r-a)>=x: #a->r->b
            print(2)
        elif (a-l>=x and r-b>=x): #a->l->r->b
            print(3)
        else:
            print(-1)