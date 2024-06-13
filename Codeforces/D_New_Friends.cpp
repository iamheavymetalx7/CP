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

    const int maxn = 200010;
    vector<int> rankk(maxn);
    vector<int> par(maxn);

    int find(int x){
        auto p=par[x];

        while(p!=par[p]){
            par[p]=par[par[p]];
            p=par[p];
        }
        return p;
    }

    void merge(int x, int y){
        auto p1 = find(x);
        auto p2 = find(y);

        if (p1==p2){
            return ;
        }

        if (rankk[p1]<rankk[p2]){
            par[p1]=p2;
            rankk[p2]+=rankk[p1];
        }
        else{
            par[p2]=p1;
            rankk[p1]+=rankk[p2];
        }
    }
    
    void solve()
    {
        int n,m;
        cin>>n>>m;
        for(int i=0;i<m;i++){
            int x,y;
            cin>>x>>y;
            merge(x,y);

        }

        int ans =0;
        for(int i=1;i<=n;i++){
            if (find(i)==i){
                ans += (rankk[i]*(rankk[i]-1))/2;
            }
        }

        cout<<ans-m<<endl;

    
    
    }
    
    signed main()
    {
        fast
        // int t; cin>>t; while(t--)
    
        #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
        #endif
        for(int i=1;i<=maxn;i++){
            par[i]=i;
            rankk[i]=1;
        }
        solve();
        return 0;
    }