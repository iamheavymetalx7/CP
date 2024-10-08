import sys
sys.stdout = open('output.txt','w')
#sys.stdin = open('CP_Oct/input.txt','r')
import math, itertools, collections

def numRollsToTarget(d: int, f: int, target: int) -> int:
    def helper(h, d, target):
        print(d,target)

        if target <= 0 or target > (d * f):
            return 0
        if d == 1:
            return 1        
        if (d, target) in h:
            return h[(d, target)]
        res = 0
        for i in range(1, f + 1):
            res += helper(h, d - 1, target - i)    

        h[(d, target)] = res
        return h[(d, target)]
    
    h = {}
    print(helper(h, d, target) % (10 ** 9 + 7))

numRollsToTarget(3,6,7)