import sys
##https://atcoder.jp/contests/abc278/tasks/abc278_c

sys.stdout = open('/Users/nitishkumar/Documents/Template_Codes/Python/CP_Oct/output.txt','w')
sys.stdin = open('/Users/nitishkumar/Documents/Template_Codes/Python/CP_Oct/input.txt','r')

from collections import defaultdict

N,Q=map(int, input().split())
'''
for i in range(N):
    dic[i+1]=set()
for i in range(Q):
    arr =list(map(int, input().split()))
    if arr[0]==1:
        dic[arr[1]].add(arr[2])
    elif arr[0]==2:
        dic[arr[1]].discard(arr[2])
    elif arr[0]==3:
        if arr[1] in dic[arr[2]]:
            if arr[2] in dic[arr[1]]:
                print("Yes")
            else:
                print("No")
        else:
            print("No")

'''
follows=set()

for i in range(Q):
    arr=list(map(int, input().split()))
    if arr[0]==1:
        follows.add((arr[1],arr[2]))
    elif arr[0]==2:
        follows.discard((arr[1],arr[2]))
    elif arr[0]==3:
        if ((arr[1],arr[2])) in follows:
            if ((arr[2],arr[1])) in follows:
                print("Yes")
            else:
                print("No")
        else:
            print("No")


