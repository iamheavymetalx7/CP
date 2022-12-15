import sys
import math, itertools, collections

sys.stdin=open('/Users/nitishkumar/Documents/Template_Codes/Python/CP_Oct/input.txt','r')
sys.stdout=open('/Users/nitishkumar/Documents/Template_Codes/Python/CP_Oct/output.txt','w')
for _ in range (int(input())):
    n,c = [i for i in input().split()]
    n = int(n)
    s = input().strip()
    s += s
    nxt = [0]*(len(s))
    for i in range (len(s)):
        if s[i]=='g':
            nxt[i] = i
    print(nxt) 
    for i in range (len(s)-2, -1, -1):
        if s[i]!='g':
            nxt[i] = nxt[i+1]
    print(nxt,"*")
    ans = 0
    for i in range (len(s)):
        if s[i]==c:
            ans = max(ans, nxt[i]-i)
    print(ans)
