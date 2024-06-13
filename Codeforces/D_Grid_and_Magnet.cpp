#include <bits/stdc++.h>
using namespace std;

#define DEBUG(x...) { cout << "(" << #x << ")" << " = ( "; Print(x); }
template <typename T1> void Print(T1 t1) { cout << t1 << " )" << endl; }
template <typename T1, typename... T2>
void Print(T1 t1, T2... t2) { cout << t1 << " , "; Print(t2...); }
 

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
int n,m;


vector<int> dx = {1,0,-1,0};
vector<int> dy = {0,1,0,-1};

int bfs(int x, int y, vector<vector<char>>&vec,vector<vector<int>>&magnets,vector<vector<int>>&vis){
    // cout<<"bsf "<<x<<" "<<y<<endl;
    queue<vector<int>> q;
    set<int> st;
    vis[x][y]=1;
    q.push({x,y});
    st.insert(x*m+y);
    while(!q.empty()){
        auto v = q.front();
        q.pop();
        auto xx =v[0],yy=v[1];

        for (int i=0;i<4;i++){
            int nx = xx+dx[i];
            int ny = yy+dy[i];
            if (nx<0 || nx>=n || ny<0 || ny>=m) continue;
            // cout<<nx<<" bfs call "<<ny<<endl;
            int nxy = nx*m+ny;
            if (st.count(nxy)>0) continue;
            st.insert(nxy);
            vis[nx][ny]=1;
            if (magnets[nx][ny]==1) continue;
            q.push({nx,ny});


        }

    }
    return st.size();

}
    
void solve()
{
    cin>>n>>m;
    vector<vector<char>> vec(n, vector<char>(m));
    vector<vector<int>> magnets(n,vector<int>(m,0));
    vector<vector<int>> vis(n,vector<int>(m,0));
    
    rep(i,0,n){
        rep(j,0,m){
            cin>>vec[i][j];
        }
    }

    rep(i,0,n){
        rep(j,0,m){
            if (vec[i][j]=='#'){
                magnets[i][j]=1;
                // cout<<i<<" "<<j</<endl;
                rep(k,0,4){
                    int ni=i+dx[k], nj=j+dy[k];
                    if (ni<0 || ni>=n || nj<0 || nj>=m) continue;
                    // cout<<ni<<" "<<nj<<" ...."<<endl;
                    magnets[ni][nj]=1;
                }
            }
        }
    }
    
    

    // rep(i,0,n){
    //     rep(j,0,m){
    //         cout<<magnets[i][j]<<' ';
    //     }
    //     cout<<endl;
    // }
    // cout<<endl;

    int ans=1;
    rep(i,0,n){
        rep(j,0,m){
            if (vis[i][j]==1) continue;
            if (magnets[i][j]==1) continue;
            // cout<<bfs(i,j,vec,magnets,vis)<<" "<<i<<" "<<j<<endl;
            ans = max(ans, bfs(i,j,vec,magnets,vis));
            }
        }

    cout<<ans<<endl;

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