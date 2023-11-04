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


    
    void solve()
    {
        int n,q;
        cin>>n>>q;
        
        int maxN = 19;

        vector<vector<int>> sparse(n,vector<int>(maxN,inf));

        vector<int> v(n);
        rep(i,0,n){
            cin>>v[i];
            sparse[i][0]=v[i];
        }

        for(int j=1;j<maxN;j++){
            for(int i=0; i+(1<<j)<=n;i++){
                sparse[i][j] = min(sparse[i][j-1],sparse[i+(1<<(j-1))][j-1]);
            }
        }

        for(int i=0;i<q;i++){
            int l,r;
            cin>>l>>r;
            l--;
            r--;
            // cout<<l<<" "<<r<<endl;
            int k = log2(r-l+1);



            int ans = min(sparse[l][k],sparse[r-(1<<k)+1][k]);
            cout<<ans<<endl;
        }

        



     
     
     
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