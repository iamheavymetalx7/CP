## binary search application
##we need to find the maximum distance
import sys

sys.stdout = open('CP_Oct/output.txt','w')
sys.stdin = open('CP_Oct/input.txt','r')


for testcase in range(int(input())):
    n,k = map(int, input().split())
    arr=[]
    for _ in range(n):
        a=int(input())
        arr.append(a)

    def isPossible(arr,mid,k):
        cow=1
        cow_loc=arr[0]
        for i in range(1,len(arr)):
            if arr[i]-cow_loc>=mid:
                cow+=1
                cow_loc=arr[i]
                if cow>=k:
                    return True
        return False

    def binary_search(n,k,arr):
        arr.sort()
        low=1
        high = arr[-1]-arr[0]

        while(low<=high):
            mid = (low+high)>>1
            
            if isPossible(arr,mid,k):
                res=mid
                low=mid+1
            else:
                high=mid-1
        return res


    print(binary_search(n,k,arr))


