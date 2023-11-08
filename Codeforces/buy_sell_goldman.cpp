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
    {	int N,K;
        cin>>N;
        cin>>K;
        vector<int> cost(N);
        vector<int> sell(N);

        rep(i,0,N) cin>>cost[i];
        rep(i,0,N) cin>>sell[i];

        vector<pair<int,int>> prices;
        rep(i,0,N){
            prices.push_back({cost[i],sell[i]});
        }
        sort(prices.begin(),prices.end());

        int profit=0;
        for (auto x: prices){
            if (K>=x.first && x.second>=x.first){
                K += -x.first+x.second;
                profit+= x.second-x.first;
            }
        }

        cout<<profit<<endl;


    
     
    }
    
    signed main()
    {
        fast
        // int t; cin>>t; while(t--)
    
        #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
        #endif
        int q;
        cin>>q;
        while (q--){
        solve();}
        return 0;
    }   