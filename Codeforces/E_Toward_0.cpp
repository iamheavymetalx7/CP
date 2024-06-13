#include <bits/stdc++.h>
    using namespace std;
    #define int long long
    #define pi (3.141592653589)
    #define mod 1000000007
    // #define float double
    #define ff first
    #define ss second
    #define mk make_pair
    #define pb push_back
    #define rep(i, start, end) for (int i = start; i < end; i++)
    #define ld long double
    #define fast ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int inf = 1000000000000000000;
    using ii = pair<int, int>;


    unordered_map<int,double> mp;

    int n,a,x,y;

    double f(int num){
        if (num==0){
            return 0;
        }

        if (mp.find(num)!=mp.end()){
                return mp[num];
        }

        double ans = x+f(num/a);
        double tot =0;
        for (int k=2;k<=6;k++){
            tot+=f(num/k);
        }
        ans = min(ans, 6.0 /5* y+ tot/5);
        
        mp[num]=ans;
        // cout<<ans<<endl;
        return ans;


    }

    void solve()
    {
            mp[0]=0;
    
    cin>>n>>a>>x>>y;

    // cout<<n<<" "<<a<<" "<<x<<" "<<y<<endl;

    
    float c = f(n);
    cout<<setprecision(10)<<fixed<<c<<endl;
    
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