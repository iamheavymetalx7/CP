import sys
sys.stdout = open('CP_Oct/output.txt','w')
sys.stdin = open('CP_Oct/input.txt','r')
import math, itertools, collections

for testcase in range(int(input())):
    s = str(input())
    out = 'YES'
    for x, y in itertools.groupby(s): 
        if len(list(y)) == 1:
            out = 'NO'
    print(out)




