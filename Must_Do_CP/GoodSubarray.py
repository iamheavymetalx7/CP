'''
https://codeforces.com/problemset/problem/1398/C
https://www.geeksforgeeks.org/print-all-subarrays-with-0-sum/
'''
import sys

sys.stdout = open('/Users/nitishkumar/Documents/Template_Codes/Python/CP_Oct/output.txt','w')
sys.stdin = open('/Users/nitishkumar/Documents/Template_Codes/Python/CP_Oct/input.txt','r')


for testcase in range(int(input())):
    l = int(input())
    arr=[int(x) for x in str(input())]

    def count_(arr):
        dic ={0:1}
        s,tot=0,0
        for i in range(len(arr)):
            s+=arr[i]
            x=s-(i+1)

            if x not in dic:
                dic[x]=0
            tot+=dic[x]
            dic[x]+=1
        return tot
    print(count_(arr))


