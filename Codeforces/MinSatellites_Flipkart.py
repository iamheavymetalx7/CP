from bisect import *
from heapq import *
from collections import defaultdict,Counter
import sys
input = lambda: sys.stdin.readline().rstrip("\r\n")
from os import path
if(path.exists('input.txt')):
    sys.stdin = open("input.txt","r")
    sys.stdout = open("output.txt","w")

n,m = map(int, input().split())
a=[]
for _ in range(n):
    a.append(list(map(int, input().split())))



# https://www.geeksforgeeks.org/minimum-number-of-water-to-land-conversion-to-make-two-islands-connected-in-a-grid-set-2/