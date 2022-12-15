import sys
##https://codeforces.com/contest/1759/problem/B

sys.stdout = open('/Users/nitishkumar/Documents/Template_Codes/Python/CP_Oct/output.txt','w')
sys.stdin = open('/Users/nitishkumar/Documents/Template_Codes/Python/CP_Oct/input.txt','r')


for testcase in range(int(input())):
    m, s = map(int, input().split())
    l = set(list(map(int, input().split())))
    
    i=1
    add=0
    while add<s:
        if i not in l:
            add+=i
        l.add(i)
        i+=1
    if add==s and len(l)>=max(list(l)):
        print("YES")
    else:
        print("NO")


    


