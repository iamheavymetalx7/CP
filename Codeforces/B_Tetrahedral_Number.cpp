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
        cout<<n<<endl;
        vector<vector<int>> vec;
        for(int i=0;i<=n;i++){
            for(int j=0;j<=n;j++){
                for(int k=0;j<=n;k++){
                    if (i+j+k <= n){

                        vec.push_back({i,j,k});
                    }
                }
            }
        }

        sort(vec.begin(),vec.end());

        for(int i=0;i<vec.size();i++){
            cout<<vec[i][0]<<" "<<vec[i][i]<<" "<<vec[i][2]<<endl;

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