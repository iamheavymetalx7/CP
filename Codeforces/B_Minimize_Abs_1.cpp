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
        vector<int> a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
    
        vector<int> ans(n);
        for(int i=0;i<n;i++){
            if (a[i]<=l){
                ans[i]=l;
            }
            else if (a[i]>=r){
                ans[i]=r;

            }
            else
            {
                ans[i]=a[i];
            }
            
        }
    
        for(int i=0;i<n;i++){
            cout<<ans[i]<<" ";
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