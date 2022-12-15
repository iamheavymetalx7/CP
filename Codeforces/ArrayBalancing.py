
import sys
sys.stdout = open('CP_Oct/output.txt','w')
sys.stdin = open('CP_Oct/input.txt','r')
import math, itertools, collections

for testcase in range(int(input())):
    n = int(input())
    a = [*map(int, input().split())]
    b = [*map(int, input().split())]