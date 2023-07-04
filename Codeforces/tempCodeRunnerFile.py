    n, x = map(int, input().split())
    a = list(map(int, input().split()))
    mx = [-INF for i in range(n + 1)]
    mx[0] = 0
    for l in range(n):
        s = 0
        for r in range(l, n):
            s += a[r]
            mx[r - l + 1] = max(mx[r - l + 1], s)

    ans = [0 for i in range(n + 1)]
    
    for k in range(n + 1):
        bst = 0
        for i in range(n + 1):
            bst = max(bst, mx[i] + min(k, i) * x)
        ans[k] = bst
    print(" ".join([str(x) for x in ans]))
    
