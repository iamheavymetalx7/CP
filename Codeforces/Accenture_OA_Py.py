from bisect import *
from heapq import *
from collections import defaultdict,Counter
import sys
input = lambda: sys.stdin.readline().rstrip("\r\n")
from os import path
if(path.exists('input.txt')):
    sys.stdin = open("input.txt","r")
    sys.stdout = open("output.txt","w")

n,m1,m2,m3,m4 = map(int, input().split())
arr=[]

for _ in range(n):
    name,size = map(str,input().split())
    size = int(size)
    arr.append([name,size])
S,M,L,X =[],[],[],[]
for x,y in arr:
    if y>=m1 and y<m2:
        S.append(x)
    elif y>=m2 and y<m3:
        M.append(x)
    elif y>=3 and y<m4:
        L.append(x)
    else:
        X.append(x)

print("S:")
print(*S, sep="\n")
print("\n")

print("M:")
print(*M, sep="\n")
print("\n")


print("L:")
print(*L, sep="\n")
print("\n")


print("X:")
print(*X, sep="\n")
print("\n")
