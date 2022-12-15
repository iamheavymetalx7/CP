## Application of binary search
## striver code

'''
link:https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=9&page=show_problem&problem=655
'''
##this gives the maximum number of pages
import sys

sys.stdout = open('CP_Oct/output.txt','w')
sys.stdin = open('CP_Oct/input.txt','r')

for testcase in range(int(input())):
    k = int(input())
    arr = [*map(int, input().split())]


    def isPossible(arr,mid,k):
        stud_count = 0
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
 

    def binary_search(k,arr):
        low = min(arr)
        high = sum(arr)
        while(low<=high): 
            mid = (low+high)>>1 
            
            if isPossible(arr,mid,k):
                res=mid
                high=mid-1
            else:
                low=mid+1
        return low


    print(binary_search(k,arr))

'''
k is the number of students, arr is the aray
containing pages
'''


