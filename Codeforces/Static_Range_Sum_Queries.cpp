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

     vector<int> vec(n);
     rep(i,0,n){
        cin>>vec[i];
     }

     vector<int> pref(n+1,0);
     pref[1] = vec[0];

     for(int i=2;i<pref.size();i++)
     {
        pref[i]=pref[i-1]+vec[i-1];
     }

     for(int i=0;i<q;i++){
        int l,r;
        cin>>l>>r;
        int ans = pref[r]-pref[l-1];
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