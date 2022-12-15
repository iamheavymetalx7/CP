
import sys

sys.stdout = open('/Users/nitishkumar/Documents/Template_Codes/Python/CP/Codeforces/output.txt','w')
sys.stdin = open('/Users/nitishkumar/Documents/Template_Codes/Python/CP/Codeforces/input.txt','r')

def solve(n,arr):
    count=0
    for i in range(len(arr)):
        while arr[i]%2==0:
            arr[i]=arr[i]//2
            count+=1

    rem=n-count

    if rem<=0:
        return(0)

    int_i=[]
    for i in range(1,n+1):
        cnt=0
        while i%2==0:
            i=i//2
            cnt+=1
        int_i.append(cnt)
    int_i.sort(reverse=True)

    c=0
    for j in int_i:
        c+=1
        rem=rem-j
        if rem<=0:
            return(c)
    return(-1)
        



for testcase in range(int(input())):
    n=int(input())
    arr=list(map(int, input().split()))
    z=solve(n,arr)
    print(z)          


    
