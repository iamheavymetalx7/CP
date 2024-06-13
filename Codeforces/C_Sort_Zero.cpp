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
        for(auto &x:v){
            cin>>x;
        }
        int lidx=-1;
        for(int i=n-2;i>=0;i--){
            if (v[i]>v[i+1]){
                lidx=i;
                break;
            }
        }
        if(lidx==-1){
            cout<<0<<endl;
            return;
        }
        map<int,int> mp;
        int ans =0;
        for(int i=0;i<=lidx;i++){
            mp[v[i]]++;
        }
        int pos = lidx;

        for(int i=n-1;i>=lidx;i--){
            if (mp.find(v[i])!=mp.end()){
                pos=i;
                break;
            }
        }


        for(int i=lidx;i<=pos;i++){
            mp[v[i]]++;
        }
        cout<<mp.size()<<endl;
    
    }
    
    signed main()
    {
        fast
    
        #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
        #endif
        int t; cin>>t; while(t--)
        solve();
        return 0;
    }