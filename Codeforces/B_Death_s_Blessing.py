from collections import defaultdict

'''
Approach :
Note that each monset has to be killed so total will always contain sum(A).
Now one thing to note here is that each monset has a skill i.e. its death blessing
is added to either one of its neighbor (if it is present at the end) or either two
of its neighbors (if it has both left and right neighbors) and none, if it is the last monster.


Now on careful observation we see that we can find bmax and keep deleteing from left until we hit
bmax and then keep deleting from right until we again hit bmax, by doing so we are 
ensuring that, each bi is added only once, and like we said now since Bmax is maximum
we will delete the monster corresponding to Bmax with only Ai and so we add to total
sum(B)-Bmax
'''

for testcase in range(int(input())):
    n=int(input())  
    A=list(map(int, input().split()))
    B=list(map(int, input().split()))

    B_max=max(B)

    print(sum(A)+sum(B)-B_max)
