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
        int  n;
        cin>>n;
        n*=2;
        vector<vector<char>> vec(n,vector<char>(n,'.'));
        int cntx=0,cnty=0;
        for(int i=0;i<n;i++){
            cntx+=1;
            for(int j=0;j<n;j++){
                cnty+=1;
                vec[i][j]='#';
                if (cnty>=2){
                    cnty=0;
                    j+=2;
                }
            }
            if (cntx>=2){
                cntx=0;
                i+=2;
            }
        }
    

        for(int i=2;i<n;i++){
            cntx+=1;
            for(int j=2;j<n;j++){
                cnty+=1;
                vec[i][j]='#';
                if (cnty>=2){
                    cnty=0;
                    j+=2;
                }
            }
            if (cntx>=2){
                cntx=0;
                i+=2;
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout<<vec[i][j];
            }
            cout<<endl;
        }
    
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