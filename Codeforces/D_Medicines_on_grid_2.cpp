#include <bits/stdc++.h>
    using namespace std;
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
    using ii = pair<int, int>;
    
const int M=205;
const int N=305;

string s[M];
int r[N],c[N],e[N];
int dist[N][N];
int pw[N][N];

int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};

void solve(){
    int h,w;cin>>h>>w;
    for(int i=0;i<h;i++)cin>>s[i];
    int n;cin>>n;
    for(int i=0;i<n;i++){
        cin>>r[i]>>c[i]>>e[i],r[i]--,c[i]--;
        pw[r[i]][c[i]]=e[i];
    }
    queue<pair<int,int>> q;
    int tx=0,ty=0;
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            dist[i][j]=-1;
            if(s[i][j]=='S'){
                dist[i][j]=max(0,pw[i][j]);
                q.push({i,j});
            }
            if(s[i][j]=='T')tx=i,ty=j;
        }
    }
    while(!q.empty()){
        int x=q.front().first;
        int y=q.front().second;
        cout<<x<<" "<<y<<endl;
        q.pop();
        if(dist[x][y]==0)continue;
        for(int i=0;i<4;i++){
            int nx=x+dx[i];
            int ny=y+dy[i];
            if(nx<0||nx>=h||ny<0||ny>=w)continue;
            if(s[nx][ny]=='#')continue;
            if(dist[nx][ny]<max(dist[x][y]-1,pw[nx][ny])){
                dist[nx][ny]=max(dist[x][y]-1,pw[nx][ny]);
                q.push({nx,ny});
            }
        }
    }
    if(dist[tx][ty]!=-1)cout<<"Yes\n";
    else cout<<"No\n";
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