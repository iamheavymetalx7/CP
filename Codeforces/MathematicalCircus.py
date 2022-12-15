# https://codeforces.com/problemset/problem/1719/B
from collections import deque
import sys

sys.stdout = open('/Users/nitishkumar/Documents/Template_Codes/Python/CP/Codeforces/output.txt','w')
sys.stdin = open('/Users/nitishkumar/Documents/Template_Codes/Python/CP/Codeforces/input.txt','r')

## Cases 4k1+ and 4k+3:
##if k is odd, always a pair exists, given by odd, even
## this is becasue odd+k is divisible by 2 and even divi by 2
##hence divisible by 4

for testcase in range(int(input())):

    n,k=map(int,input().split())

    ## Cases : 4k and 4k+2
    ## If 4k: not possible, since even+odd is odd and
    ##any elt of the form 4m+2 when add with 4k, remains as such
    ## so this case doesnt help

    if k%2:
        print("YES")
        for i in range(1,n,2):
            print(i," ",i+1)


    ## If 4k+2: 4k+2+(4m+2)=4k' and it helps, 
    ## and if elt of form 4m, add with odd itself
    ## so alternate depending on remainder with 4


    else:
        if k%4==0:
            print("NO")
        else:
            print("YES")
            flg=0
            for i in range(1,n,2):
                if flg:
                    print(i," ",i+1)
                else:
                    print(i+1," ",i)

                flg=1-flg













'''
^----------- wrong approach!!!! ----------^
for testcase in range(int(input())):
    n,k=map(int,input().split())
    A,B=[],[]
    cnt=0
    for j in range(n):
        if (j+1+k)%4==0:
            print(j+1,"##")
            cnt+=1
            A.append(j+1)
         
        elif (j+1)%4==0:
            print(j+1,"**")
            cnt+=1
            A.append(j+1)
        else:
            B.append(j+1)
    print(len(A),len(B))
    print(cnt)
    if cnt==n//2:
        print("YES")
        for i in range(len(A)):
            if A[i]%4==0:
                print(B[i],A[i])
            else:
                print(A[i], B[i])
    
    else:
        print("NO")

'''