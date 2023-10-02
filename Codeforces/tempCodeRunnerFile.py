    sign,num = s.split()
        num = int(num)
        dp = [0 for _ in range(k+1)]
        mod=  int(998244353)

        if sign=="+":
            for x in range(k,num-1,-1):
                dp[x]+=dp[x-num]
                dp[x]%=mod
        else:
            for x in range(num,k+1):
                dp[x]-=dp[x-num]
                dp[x]%=mod
        
        print(dp[k])