for testcase in range(int(input())):
    n=int(input())
    A=list(map(int, input().split()))

    A.sort()
    
    summ=sum(A)
    sum1,maxi=0,0
    for i in range(len(A)):
        sum1+=A[i]
        abs_diff=abs(sum1)-abs(summ-sum1)

        maxi=max(maxi,abs_diff)

    print(maxi)



'''

for testcase in range(int(input())):
    n=int(input())
    A=list(map(int, input().split()))
    
    total = sum(A)
    
    print(abs(total))
    
'''