## this is a difficult qn that i have done in recent times
## if u do it again be careful
import sys, threading
import math
from os import path
from collections import defaultdict, Counter, deque
from bisect import *
from string import ascii_lowercase
from functools import cmp_to_key
import heapq


def lcm(a, b):
    return (a*b)//(math.gcd(a,b))

def dfs(node,ans,adj,vis):
    if vis[node]:
        return
    
    for child in adj[node]:
        dfs(child,ans,adj,vis)

        for x in ans[child]:
            ans[node].add(x)
    vis[node]=1
    return


def solve(t):
    n=int(input())
    ar=[]
    for i in range(n):
        ar.append(str(input()))

    adj=defaultdict(list)
    vis=[0]*n
    ans=[{i+1} for i in range(n)]
    for i in range(n):
        for j in range(n):
            if ar[i][j]=="1":
                adj[j].append(i)

    for i in range(0,n):
        dfs(i,ans,adj,vis)

    for an in ans:
        print(len(an),*an)



def main():
    t = 1
    if path.exists("/Users/nitishkumar/Documents/Template_Codes/Python/CP/Codeforces/input.txt"):
        sys.stdin = open("/Users/nitishkumar/Documents/Template_Codes/Python/CP/Codeforces/input.txt", 'r')
        sys.stdout = open("/Users/nitishkumar/Documents/Template_Codes/Python/CP/Codeforces/output.txt", 'w')
    sys.setrecursionlimit(10**5) 
    t = int(input())
    for i in range(t):
        solve(i+1)
 

if __name__ == '__main__':
    main()  







'''

^-------- Wrong Answer ------->

------ The problem in this approach is that the ans first prints
the index 2 and so on, we wish to print in Ai 1<=i<=n order,
but that is not happening here -------

for testcase in range(int(input())):
    n=int(input())
    adj = defaultdict(list)
    vis=[0]*n
    ans=defaultdict(set)
## here we make the adj matrix.
## if bij=1, directed edge from j to i, j being the parent
## and i being the child.
    for i in range(n):
        string=str(input())
        for j in range(len(string)):
            if string[j]=="1":
                adj[j].append(i)
## in the dfs we visit the child first always, and for each chils
## we add that nodes present in child to the parent node
## morevoer we also node+1 in the child in order to prevent ambiguity    

##now we run a dfs call
    for i in range(0,n):
        dfs(i,ans,adj,vis)
    
## now we print the reqd ans
    for j in ans:
        print(len(ans[j]),end=" ")
        for i in ans[j]:
            print(i,end=" ")

        print()
'''