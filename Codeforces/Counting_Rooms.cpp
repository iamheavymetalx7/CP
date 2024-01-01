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

    vector<vector<int>> dire = {{1,0},{0,1},{-1,0},{0,-1}};

    void dfs(int x,int y, vector<vector<int>>& vis, vector<vector<char>> &mat){
        vis[x][y]=1;

        for (auto dd:dire){
            int dx= x+dd[0];
            int dy = y+dd[1];

            // cout<<"isnide dfs: "<<dx<<" "<<dy<<endl;
            if (dx>=0 && dx<mat.size() && dy>=0 && dy<mat[0].size() && !vis[dx][dy] && mat[dx][dy]=='.'){
                dfs(dx,dy,vis,mat);
            }
        }

        
    }
    
    void solve()
    { int n,m;
    cin>>n>>m;
    vector<vector<char>> mat(n,vector<char> (m));

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>mat[i][j];
        }
    }

    vector<vector<int>> vis(n,vector<int>(m,0));
    int cnt=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if (!vis[i][j] && mat[i][j]=='.' ){
                // cout<<i<<" "<<j<<endl;
                    cnt++;
                    dfs(i,j,vis,mat);

            }
        }
    }

    cout<<cnt<<endl;
    
    
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