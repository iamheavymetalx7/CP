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
        int n; cin>>n;
        vector<int> v(n);
        for(int i=0;i<n;i++){
            cin>>v[i];
        }

        int cnt=0;
        vector<pair<int,int>> vec;
        for(int i=0;i<n;i++){
            while((i+1)!=v[i]){
                vec.push_back({v[i],v[v[i]-1]});

                swap(v[i],v[v[i]-1]);
            }
        }

        cout<<vec.size()<<endl;
        for(int i=vec.size()-1;i>=0;i--){
            int x = vec[i].first;
            int y = vec[i].second;
            if (x<y){
                cout<<x<<" "<<y<<endl;
            }
            else
            {
                cout<<y<<" "<<x<<endl;
            }
            
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