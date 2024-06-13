#include <bits/stdc++.h>
    using namespace std;
    #define int long long
    #define pi (3.141592653589)
    #define mod 1000000007
    #define float double
    #define ff first
    #define ss second
    #define mk make_pair
    #define pb push_back
    #define rep(i, start, end) for (int i = start; i < end; i++)
    #define ld long double
    #define fast ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int inf = 1000000000000000000;
    using ii = pair<int, int>;
    map<int,int> mp;

    // int recur(int x){
    //     if(x<0){
    //         return 0;
    //     }
    //     if(x==0){
    //         return 1;
    //     }
    //     if(mp.count(x)>0){
    //         return mp[x];x
    //     }

    //     int ans =0;
    //     for(int i=1;i<=6;i++){
    //         ans = (ans+recur(x-i))%mod;
    //     }

    //     mp[x]=ans;
    //     return mp[x];
        

    // }

    void solve()
    {
        int n;
        cin>>n;
        int dp[1000005];
        memset(dp,0,sizeof(dp));
        dp[0]=1;x

        for(int i=1;i<=n;i++){
            for(int j=1;j<=6;j++){
                if (i-j>=0){
                    dp[i] = (dp[i]+dp[i-j])%mod;
                }
            }
        }
        cout<<dp[n]<<endl;
    }
    
    signed main()
    {
        fast
        // int t; cin>>t; while(t--)
    
        #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
        #endif
        solve();
        return 0;
    }