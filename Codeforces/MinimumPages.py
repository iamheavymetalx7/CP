## Application of binary search
## striver code

'''
link:https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=9&page=show_problem&problem=655
2. https://leetcode.com/problems/split-array-largest-sum/
'''
##this gives the maximum number of pages
import sys

sys.stdout = open('CP_Oct/output.txt','w')
sys.stdin = open('CP_Oct/input.txt','r')

for testcase in range(int(input())):
    n,k = map(int, input().split())
    arr = [*map(int, input().split())]


    def isPossible(arr,mid,k):
        stud_count =0
        pages=0
        for i in range(0,len(arr)):
            if arr[i]>mid:
                return False
            if (pages+arr[i]>mid):
                pages = arr[i]
                stud_count+=1
            else:
                pages+=arr[i]
        if stud_count<k: return True

        return False
 

    def binary_search(n,k,arr):
        arr.sort()

        low = min(arr)
        high = sum(arr)
        res=-1
        while(low<=high): 
            mid = (low+high)>>1 
            
            if isPossible(arr,mid,k):
                res=mid
                high=mid-1
            else:
                low=mid+1
        return res


    print(binary_search(n,k,arr))



###########
# Another variation from GFG
#########


class Solution:
    '''    
    def binarysearch(arr,target):
        n=len(nums)
        low==0
        high=n-1
        
        while low<=high:
            mid = low+(high-low)//2
            
            if target>arr[mid]:
                low=high+1
            elif target < arr[mid]:
                high=mid-1
            else:
                return mid
        return -1
        
    '''            

    #Function to find minimum number of pages.
    def findPages(self,A, N, M):
        #code here
        
        if M>N:
            return -1
        low=0
        high=sum(A)
        
        ans=-1
        
        while low<=high:
            mid=low+(high-low)//2
            
            if self.isPossible(A,mid,M):
                ans=mid
                high=mid-1
            else:
                low=mid+1
        return ans
        
        
    def isPossible(self,arr,mid,m):
        n=len(arr)
        pageSum=0
        stdCnt=1
        for i in range(n):
            if pageSum+arr[i]<=mid:
                pageSum+=arr[i]
            else:
                stdCnt+=1
                if stdCnt>m or arr[i]>mid:
                    return False
                pageSum=arr[i]
        return True
