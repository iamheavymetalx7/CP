import sys
import math, itertools, collections
##use of stack
sys.stdin=open('/Users/nitishkumar/Documents/Template_Codes/Python/CP_Oct/input.txt','r')
sys.stdout=open('/Users/nitishkumar/Documents/Template_Codes/Python/CP_Oct/output.txt','w')

def solve():
    n=int(input())
    arr=[]

    for i in range(n):
        x=int(input())
        if x==1:
            arr.append(1)
        else:
            while((arr[-1]+1)!=x):
                arr.pop()
            arr.pop()
            arr.append(x)
        for i in range(len(arr)-1):
            print(str(arr[i])+".",end="")
        print(arr[-1])
##if 1, i append it and print
## if not 1, pop until arr[-1]+1!=x
##and one more arr.pop at the end to ensure, the new append is at the right place

for _ in range(int(input())):
    solve()