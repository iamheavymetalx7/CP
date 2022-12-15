import sys

sys.stdout = open('/Users/nitishkumar/Documents/Template_Codes/Python/CP/Codeforces/output.txt','w')
sys.stdin = open('/Users/nitishkumar/Documents/Template_Codes/Python/CP/Codeforces/input.txt','r')


for testcase in range(int(input())):
    n,a,b = map(int, input().split())
    arr1=[(i+1) for i in range(n)]
    arr2=[0]*n
    arr2[:a]=arr1[:a]
    arr2[-b:]=arr1[-b:]
    

    for j in range(a,n-b):
        arr2[j]=arr1[j]
    arr2[a:n-b]=arr2[a:n-b][::-1]
    if n==a and n==b:
        print("Yes")
    else:
        if arr1==arr2:
            print("No")
        else:
            print("Yes")

