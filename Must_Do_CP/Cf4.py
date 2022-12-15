import sys
import math, itertools, collections

sys.stdin=open('/Users/nitishkumar/Documents/Template_Codes/Python/CP_Oct/input.txt','r')
sys.stdout=open('/Users/nitishkumar/Documents/Template_Codes/Python/CP_Oct/output.txt','w')



for _ in range (int(input())):
    n = int(input())
    a = [int(i) for i in input().split()]
    cnt = []
    for i in range (1,n+1):
        c = 0
        while (i%2==0):
            i//=2
            c+=1
        cnt.append(c)
    cnt.sort(reverse=1)
    given = 0
    for i in a:
        while(i%2==0):
            i//=2
            given += 1
    req = n - given
    ans = 0
    for i in cnt:
        if req<=0:
            break
        req -= i
        ans+=1
    if req<=0:
        print(ans)
    else:
        print(-1)