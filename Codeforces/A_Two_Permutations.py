for testcase in range(int(input())):    
    n,a,b = map(int, input().split())

    if a+b<=n-2 or (n==a and n==b):
        print("Yes")
    else:
        print("No")