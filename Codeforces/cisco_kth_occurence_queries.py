from bisect import *
from heapq import *
from collections import defaultdict,Counter
import sys

input = lambda: sys.stdin.readline().rstrip("\r\n")

from os import path

# if(path.exists('input.txt')):
#     sys.stdin = open("input.txt","r")
#     sys.stdout = open("output.txt","w")
n=int(input())
a = list(map( int,input().split()))
x=int(input())
q = int(input())
b = list(map( int,input().split()))

dic = defaultdict(int)
cnt=1
for i, ele in enumerate(a):
  if x==ele:
    dic[cnt]=i+1
    cnt+=1

for x in b:
  if x not in dic:
    print(-1)
  else:
    print(dic[x])