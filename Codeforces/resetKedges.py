import sys
from xml.dom import minidom

sys.stdout = open('/Users/nitishkumar/Documents/Template_Codes/Python/CP_Oct/output.txt','w')
sys.stdin = open('/Users/nitishkumar/Documents/Template_Codes/Python/CP_Oct/input.txt','r')

def solve():
    n,k=map(int,input().split())
    arr = [-1,0]+list(map(int, input().split()))


    l, r =1, n-1

    while l<r:
        m=(l+r)//2
        tot=0
        height = [0]*(n+1)

        for i in range(n,1,-1):
            if height[i]==m-1 and arr[i]!=1:
                tot+=1
            else:
                height[arr[i]] =  max(height[arr[i]],height[i]+1)
        
        if tot<=k:
            r=m
        else:
            l=m+1
    print(l)

t=int(input())
for _ in range(t):
    solve()