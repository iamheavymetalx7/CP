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

    #define ar array
    const int max_n = 1e3+5;


    // reference solution : https://github.com/ncduy0303/cses-solutions/blob/master/src/1193.cpp

    int n,m, pre[max_n][max_n];

    char grid[max_n][max_n];

    const int d=4;
    const int dx[] = {0, 1, 0, -1};
    const int dy[] = {1, 0, -1, 0};

    bool end(int i,int j){
        return grid[i][j]=='B';
    }

    bool ok(int i,int j){
        return (i>=0 && i<n && j>=0 && j<m && grid[i][j]!='#' && pre[i][j]==-1);
    }

    const string ds = "RDLU";

    
    void solve()
    {
        cin>>n>>m;
        queue<pair<int,int>> q;

        memset(pre,-1,sizeof(pre));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>grid[i][j];

                if (grid[i][j]=='A'){
                    q.push({i,j});
                }
            }
        }

        while(!q.empty()){
            auto [i,j] = q.front(); q.pop();
            for(int k=0;k<d;k++){
                int ni =  i+dx[k];
                int nj = j+dy[k];
                if (ok(ni,nj)){
                    q.push({ni,nj});
                    pre[ni][nj]=k;
                    if (end(ni,nj)){
                        string ans;
                        while(grid[ni][nj]!='A'){
                            int nk = pre[ni][nj];
                            ans+=ds[nk];
                            ni -= dx[nk];
                            nj -= dy[nk];
                        }

                        reverse(ans.begin(), ans.end());
                        cout<<"YES\n"<<ans.size()<<"\n"<< ans<<endl;
                        return;
                    }

                }
            }
        }

        cout<<"NO \n";


    
    
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