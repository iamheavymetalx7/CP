##https://codeforces.com/problemset/problem/1088/B



from collections import deque
import sys

sys.stdout = open('/Users/nitishkumar/Documents/Template_Codes/Python/CP/Codeforces/output.txt','w')
sys.stdin = open('/Users/nitishkumar/Documents/Template_Codes/Python/CP/Codeforces/input.txt','r')


from heapq import heapify, heappop, heappush

n,k=map(int,input().split())
A=list(map(int, input().split()))

##another approach is to keep a cumulative
##subtracted value instead of looping thro and 
##updating arr, and now
##first sort the array, then subtract the cumu subtacted val
## and then while elt is 0 keep increasing the pointer...


#heappush(heap, ele): This function
#  is used to insert the element
#  mentioned in its arguments into a heap.
#  The order is adjusted, so that heap
# structure is maintained.

#heappop(heap): This function is 
# used to remove and return the 
# smallest element from the heap. 
# The order is adjusted, so that 
# heap structure is maintained

heapify(A)
sub=0
for i in range(k):
    if len(A)==0:
        print(0)
    else:
        print(A[0]-sub)
        sub+=A[0]-sub

        while (len(A)!=0 and A[0]-sub<=0):
            heappop(A)

