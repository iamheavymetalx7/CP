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

int dx[] = { 1,0,-1,0,1,1,-1,-1 }; int dy[] = { 0,1,0,-1,1,-1,1,-1 };
template<class T> using P = pair<T, T>;


void solve()
{
    int n,m;
    cin>>n>>m;
    vector<vector<char>> s(n,vector<char>(m));

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>s[i][j];
        }
    }
    vector<vector<bool>> used(n,vector<bool>(m));
    int ans =0;


    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if (used[i][j] or s[i][j]=='.') continue;
            queue<P<int>> que;
            que.push({i,j});
            while(!que.empty()){
                P<int> p =que.front(); que.pop();
                int x=p.first, y=p.second;
                used[x][y]=true;
                for(int d=0;d<8;d++){
                    int nx = x+dx[d];
                    int ny = y+dy[d];
                    if(0<=nx && nx<n && 0<=ny && ny<m && !used[nx][ny] && s[nx][ny]=='#'){
                        used[nx][ny]=true;
                        que.push({nx,ny});
                    }
                }
            }
            ans++;
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