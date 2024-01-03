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
        int n,x;
        cin>>n>>x;
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }

        // cout<<x<<endl;
        bool f = false;
        map<int,int> mp;
        for(int i=0;i<n;i++){
            if (mp.count(arr[i])){
                cout<<mp[arr[i]]+1<<" "<<i+1<<endl;
                f=true;
                break;
            }
            mp[x-arr[i]]=i;
            // cout<<x-arr[i]<<" "<<i<<endl;
        }

        if (!f){
            cout<<"IMPOSSIBLE";
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