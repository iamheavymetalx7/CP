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
    

    float calc_dist(int x, int y, int x2, int y2){
        return sqrt(pow(x-x2,2)+pow(y-y2,2));
    }

    void solve()
    {
        int n;
        cin>>n;
        vector<int> x(n,0),y(n,0);
        for(int i=0;i<n;i++){
            cin>>x[i]>>y[i];
        }

        for(int i=0;i<n;i++){
            int cx =x[i], cy=y[i];
            int max_idx = 101;
            float dist = 0;
            for(int j=0;j<n;j++){
                float distance = calc_dist(cx,cy,x[j],y[j]);
                // cout<<distance<<"......"<<endl;
                if (distance > dist){
                    dist = distance;
                    max_idx = j+1;
                }
            }
            cout<<max_idx<<endl;
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