##https://codeforces.com/problemset/problem/1734/C
import sys

sys.stdout = open('/Users/nitishkumar/Documents/Template_Codes/Python/CP_Oct/output.txt','w')
sys.stdin = open('/Users/nitishkumar/Documents/Template_Codes/Python/CP_Oct/input.txt','r')


for testcase in range(int(input())):
    n =int(input())
    number=str(input())
    nums=list(number)
    ans=0
    for i in range(1,n+1):
        c=1
        while(c*i<=n):
            if nums[c*i-1]=='1':
                break
            if nums[c*i-1]=='0':
                ans+=i
            nums[c*i-1]='2'
            c=c+1
    print(ans)