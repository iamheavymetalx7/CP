
## Application of binary search
import sys

sys.stdout = open('CP_Oct/output.txt','w')
sys.stdin = open('CP_Oct/input.txt','r')


N,M = map(int, input().split())
arr = [*map(int, input().split())]


def ekoeko(N,M,arr):
    arr.sort()
    low=1
    high = arr[-1]
##important to note why low<high
## and why mid = low+(high-low+1)//2
    while(low<high):
        
        mid=(low + (high-low+1)//2)
        total_cut = 0
        for i in range(len(arr)):
            total_cut+=max(0,arr[i]-mid)


        if total_cut>=M:
            low=mid
        else:
            high = mid-1
    return(low)

print(ekoeko(N,M,arr))


