##https://codeforces.com/contest/1742/problem/D
import sys

sys.stdout = open('/Users/nitishkumar/Documents/Template_Codes/Python/CP_Oct/output.txt','w')
sys.stdin = open('/Users/nitishkumar/Documents/Template_Codes/Python/CP_Oct/input.txt','r')
from math import gcd

##note that: 2<= n<= 2*10^5 , therefore O(N^2) is not
##possible => O(n) approach,
##strikes me is two pointer but in reverse way
for testcase in range(int(input())):
    n =int(input())
    arr = [*map(int, input().split())]
    

    ##since a[i]<=1000, we use hashmap

    dic=[-1]*(1001)


    for i in range(n):
        dic[arr[i]]=max(i+1,dic[i])
    ##now we can write a code of O(N^2), and itwill
    ##be accepted. Why because now N=10^3 and N^2=10^6
    final_ans = -1
    m=len(dic)
    for i in range(1,m):
        for j in range(i,m):
            if gcd(i,j)==1 and dic[i]!=-1 and dic[j]!=-1:

                final_ans=max(final_ans,dic[i]+dic[j])

    print(final_ans)



'''
another approach using dictionary:
from math import gcd
 
for _ in range(int(input())):
    n = int(input())
    a = list(map(int, input().split()))
    v = {}
    for i in range(n-1, -1, -1):
        if a[i] not in v:
            v[a[i]] = i
 
    ans = -1
    for x in v:
        for y in v:
            if gcd(x, y) == 1:
                ans = max(v[x] + v[y] + 2, ans)
                
    print(ans)

'''