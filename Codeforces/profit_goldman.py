from bisect import *
from heapq import *
from collections import defaultdict,Counter
import sys
input = lambda: sys.stdin.readline().rstrip("\r\n")
from os import path
if(path.exists('input.txt')):
    sys.stdin = open("input.txt","r")
    sys.stdout = open("output.txt","w")

def solve():
    N =  int(input())
    K =  int(input())
    cost = list(map(int,input().split()))
    sell = list(map(int,input().split()))
    # print(cost,sell)
    prices=[]
    for i in range(N):
        prices.append([cost[i],sell[i]])
    prices.sort()
    print(prices)
    profit = 0
    for i,x in enumerate(prices):
        if K>=x[0]:
            if (x[1]-x[0])>=0:
                K+=(x[1]-x[0])
                profit+=x[1]-x[0]
    
    print(profit)
    # print(K)


def main():
    for _ in range(int(input())):
        solve()


if __name__ == "__main__":
    main()