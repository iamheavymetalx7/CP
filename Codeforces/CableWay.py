import sys
sys.stdout = open('output.txt','w')
sys.stdin = open('input.txt','r')
import math, itertools, collections

r,g,b  = map(int, input().split())
i =0

while(r>0 or g>0 or b>0):
    if i%3==0:
        r-=2
    elif i%3==1:
        g-=2
    else:
        b-=2
    i+=1
print(i+29)

