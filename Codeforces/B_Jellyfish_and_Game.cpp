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
        int n,m,k;
        cin>>n>>m>>k;
        vector<int> j(n),g(m);
        for(int i=0;i<n;i++){
            cin>>j[i];
        }
        vector<int> copyj = j;
        for(int i=0;i<m;i++){
            cin>>g[i];
        }
        sort(g.begin(),g.end());
        sort(j.begin(),j.end());

        for(int i=0;i<n;i++){
            cout<<j[i]<<" ";
        }
        cout<<endl;
        for(int i=0;i<m;i++){
            cout<<g[i]<<" ";
        }
        cout<<endl;

        if (j[0]<g[g.size()-1]){
            int a,b;
            a=j[0];
            b=g[g.size()-1];
            j[0]=b;
            g[g.size()-1]=a;
        }
        sort(g.begin(),g.end());
        sort(j.begin(),j.end());


        if (k%2){
            int sum=0;
            for(int i=0;i<n;i++){
                sum+=j[i];
            }
            cout<<sum<<endl;
            return;
        }
        else{
            int sum=0;
            for(int i=0;i<n;i++){
                sum+=copyj[i];
            }
            cout<<sum<<endl;
            return;
        }
        
        
    
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