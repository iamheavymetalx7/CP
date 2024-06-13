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
        vector<int> v(n);
        for(int i=0;i<n;i++){
            cin>>v[i];
        }
        vector<int> pref(n,0), suff(n,0);
        pref[0]=v[0];
        suff[n-1]=v[n-1];
        for(int i=1;i<n;i++){
            pref[i] = pref[i-1]+v[i];
        }
        for(int i=n-2;i>=0;i--){
            suff[i] = suff[i+1]+v[i];
        }
        int sum=0;
        for(auto x:v){
            sum+=x;
        }
        cout<<sum<<endl;
        vector<int> suff_min(n,1e5);
        suff_min[n-1]=0;
        int mini=1e5;
        for(int i=n-2;i>=0;i--){
            mini=min(mini,suff[i+1]);
            suff_min[i] = mini;
        }
        for(int i=0;i<n;i++){
            cout<<suff_min[i]<<" ";
        }
        cout<<endl;
        int ans=0;

        ans = max(ans,sum);
        for(int i=0;i<n;i++){
            cout<<sum-2*(pref[i]+suff_min[i])<<" "<<i<<endl;
            ans = max(ans,sum-2*(pref[i]+suff_min[i]));
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