import sys
import math, itertools, collections

sys.stdin=open('/Users/nitishkumar/Documents/Template_Codes/Python/CP_Oct/input.txt','r')
sys.stdout=open('/Users/nitishkumar/Documents/Template_Codes/Python/CP_Oct/output.txt','w')


##O(N^3)
''''
for test in range(int(input())):
    n,q=map(int, input().split())
    a1 = [*map(int, input().split())]
    for j in range(q):
        summ=0
        tp,x=map(int,input().split())
        if tp==0:
            for i in range(len(a1)):
                if a1[i]%2==1:
                    summ+=a1[i]
                else:
                    a1[i]+=x
                    summ+=a1[i]

        else:
            for i in range(len(a1)):
                if a1[i]%2==0:
                    summ+=a1[i]
                else:
                    a1[i]+=x
                    summ+=a1[i]
        print(summ)

'''


 
for _ in range (int(input())):
    n,q = [int(i) for i in input().split()]
    a = [int(i) for i in input().split()]
    s = sum(a)
    odd = 0
    for i in a:
        odd += i%2
    even = n-odd
    for __ in range (q):
        t,x = [int(i) for i in input().split()]
        if t==0:
            s += even*x
        else:
            s += odd*x
        if x%2:
            if t==0:
                odd = n
                even = 0
            else:
                odd = 0
                even = n
        print(s)