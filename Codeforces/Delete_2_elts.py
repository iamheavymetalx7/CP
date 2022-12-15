import sys

sys.stdout = open('/Users/nitishkumar/Documents/Template_Codes/Python/CP_Oct/output.txt','w')
sys.stdin = open('/Users/nitishkumar/Documents/Template_Codes/Python/CP_Oct/input.txt','r')

def fun(nums):
    n=len(nums)
    summ= sum(nums)

    avg = summ/n

    target=2*avg
    ##the problem is now reduced to two sum
    dic={}
    for i in range(len(nums)):
        dic[nums[i]]=1+dic.get(nums[i],0)   

    ans = 0

    for i in nums:
        if target-i in dic:
            if target-i!=i:
                ans+=dic[i]*dic[target-i]
                dic[i]=0
                dic[target-i]=0
            elif target-i==i:
                ans+=(dic[i]*(dic[i]-1))//2
                dic[i]=0
    return(ans)






for testcase in range(int(input())):
    n =int(input())
    nums = [*map(int, input().split())]

    func = fun(nums)

    print(func)
