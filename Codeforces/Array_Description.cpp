#include <bits/stdc++.h>
    using namespace std;
    #define int long long
    #define pi (3.141592653589)
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
    
    void solve()
    {
        int n,m;
        cin>>n>>m;

        vector<int> v(n+2);
        for(int i=1;i<=n;i++){
            cin>>v[i];
        }

        // for(int i=1;i<=n;i++){
        //     cout<<v[i]<<" ";
        // }
        // cout<<endl;

        int mod = 1e9+7;

        int dp[n+2][m+2];
        memset(dp,0, sizeof(dp));
        int ans =0;

        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if (i==1){
                    if (v[i]==0 || v[i]==j){
                        dp[i][j]=1;
                    }
                    else{
                        dp[i][j]=0;
                    }
                    
                }
                else{
                    if (v[i]==0 || v[i]==j){
                        dp[i][j] = ((dp[i-1][j]+dp[i-1][j-1])%mod+dp[i-1][j+1])%mod;
                    }
                    else{
                        dp[i][j] =0;
                    }
                }
            }
        }


        // for(int i=1;i<=n;i++){
        //     for(int j=1;j<=m;j++){
        //         cout<<dp[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        // cout<<endl;


        for(int i=1;i<=m;i++){
            ans+=dp[n][i];
            ans%=mod;
        }
        cout<<ans<<endl;



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