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
        int n,l,r;
        cin>>n>>l>>r;
        vector<int> v(n);
        for(int i=0;i<n;i++){
            cin>>v[i];
        }

        vector<int> suff(n+1,0);
        for(int i=n-1;i>=0;i--){
            suff[i] = min(suff[i+1]+v[i],(n-i)*r);
        }
        int ans = suff[0], curr=0;
        for(int i=0;i<n;i++){
            curr = min(curr+v[i],(i+1)*l);
            ans = min(ans, suff[i+1]+curr);
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