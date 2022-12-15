from collections import deque
import sys

sys.stdout = open('/Users/nitishkumar/Documents/Template_Codes/Python/CP/Codeforces/output.txt','w')
sys.stdin = open('/Users/nitishkumar/Documents/Template_Codes/Python/CP/Codeforces/input.txt','r')

def solve(n,a):
    val=False
    for i in range(1,n):
        if a[i-1]<a[i]:
            val=True
        if a[i-1]>a[i]:
            if val:
                print("NO")
                return
    print("YES")

for testcase in range(int(input())):
    n=int(input())
    a=list(map(int,input().split()))

    ##one observation is that after increment there should be no decrement
    ## we only need to check this
    ## that is increment only once

    solve(n,a)








''''

^--------- CORRECT APPROACH --------^
for testcase in range(int(input())):
    n=int(input())
    a=list(map(int,input().split()))

    a=[pow(10,9)+1]+a+[pow(10,9)+1]


    i,cnt=0,-1

    while i<len(a)-2:
        cnt+=1
        while i<len(a)-2 and a[i]>=a[i+1]:
            i+=1
        while i<len(a)-2 and a[i]<=a[i+1]:
            i=i+1
  
    if cnt==0:
        print("YES")
    else:
        print("NO")


'''
