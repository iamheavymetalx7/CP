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
    { int n,m;
    cin>>n>>m;
    vector<pair<int,pair<int,int>>> vec;

    for(int i=0;i<m;i++){
        int ui,vi,wi;
        cin>>ui>>vi>>wi;
        ui--;
        vi--;
        vec.push_back({ui,{vi,wi}});
        
    }
    
    vector<int> slowness(n);
    for(int i=0;i<n;i++){
        cin>>slowness[i];
    }

    vect




    
    }
    
    signed main()
    {
        fast
        #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
        #endif

    

        int t; cin>>t; 
        while(t--) solve();
        return 0; 
    }