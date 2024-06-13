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
        int n;
        cin>>n;
        // cout<<n<<endl;
        vector<int> q(n,0),a(n,0),b(n,0);
        for(int i=0;i<n;i++){
            cin>>q[i];
        }
        
            for(int i=0;i<n;i++){
            cin>>a[i];
        }
            for(int i=0;i<n;i++){
            cin>>b[i];
        }

        int inf = 1e18;
        int ans = 0, maxi=0;

        for(int i=0;i<n;i++){
            maxi =max(maxi,q[i]);
        }
        for(int x=0;x<=maxi;x++){
            int y = inf;
            for(int i=0;i<n;i++){
                if (q[i]<a[i]*x){
                    y=-inf;
                }
                else if (b[i]>0){
                    y =min(y,(q[i]-a[i]*x)/b[i]);
                }
            }
            ans = max(ans,x+y);
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