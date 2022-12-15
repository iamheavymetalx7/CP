import sys

sys.stdout = open('/Users/nitishkumar/Documents/Template_Codes/Python/CP/Codeforces/output.txt','w')
sys.stdin = open('/Users/nitishkumar/Documents/Template_Codes/Python/CP/Codeforces/input.txt','r')

'''
typical observation / pattern based problem
'''

for testcase in range(int(input())):
    n=int(input())
    l=set(list(map(int, input().split())))

    if len(l)==1:
        print(1)
    elif len(l)==2:
        print(n//2 +1)
    else:
        print(n)



        





'''

    rem=len(l)
    cnt=0
    while rem!=len(set(l)):
        mid=(len(l)-1)//2
        if l[mid-1]==l[mid+1]:
            l.pop(mid+1)
            rem-=1
        l.pop(mid)
        cnt+=1
        rem-=1

    cnt+=rem

    print(cnt)

    #print("******")
    rem=len(l)
    cnt=0
    while rem!=len(set(l)):
        index=len(l)-1
        l.pop(index)

        if l[0]==l[index-1]:
            #print(index-1, "if equal")
            l.pop(index-1)
            rem-=1
        cnt+=1
        rem-=1

    cnt+=rem

    print(cnt)


'''