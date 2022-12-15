import sys
sys.stdout = open('/Users/nitishkumar/Documents/Template_Codes/Python/CP_Oct/output.txt','w')
sys.stdin = open('/Users/nitishkumar/Documents/Template_Codes/Python/CP_Oct/input.txt','r')



for testcase in range(int(input())):
    numb = int(input())

    if numb%2!=0:
        print( -1)
    else:
        l= [ 1, 1, (numb//2)^1]
        print(*l)
