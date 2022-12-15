for testcase in range(int(input())):
    n=int(input())
    string = "BAN"*n
    lis=list(string)
    print(int((n+1)//2))

    l,r=2,3*n

    while l<r:
        print(l,r)
        l+=3
        r-=3
