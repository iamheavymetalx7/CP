
from collections import deque

def solve():
    n, x, y = map(int, input().split())
    x,y=min(x,y), max(x,y)

    if x != 0 or y == 0:
        print(-1)
        return
    if (n - 1) % y != 0:
        print(-1)
        return
 
    A = []
    for i in range(2, n + 1, y):
        A += [i] * y
    print(*A)
    
    
for _ in range(int(input())):
    solve()   


''''
for testcase in range(int(input())):
    n,x,y=map(int, input().split())
    if (x and y) or (x==0 and y==0):
        print(-1)
    else:
        if n%2==1:
            maxi=max(x,y)
            if (n-1)%maxi!=0:
                print(-1)
            else:
                for i in range(maxi):
                    print(1,end=" ")
                k=1+maxi+1

                while k<=n:
                    for i in range(maxi):
                        print(k,end=" ")
                    k+=maxi
            print()

        
        elif n%2==0:
            maxi=max(x,y)
            if maxi==n-1:
                for i in range(maxi):
                    print(2,end=" ")
                print()
            elif maxi==1:
                for i in range(maxi):
                    print(1,end=" ")
                k=1+maxi+1

                while k<=n:
                    for i in range(maxi):
                        print(k,end=" ")
                    k+=maxi

            else:
                print(-1)
'''