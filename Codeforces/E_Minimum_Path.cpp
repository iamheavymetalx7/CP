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


const int N = 200 * 1000 + 13;

int n, m;
vector<array<int,2>> g[N];
int d[N][2][2];
int x,y,w;

void solve()
{
cin>>n>>m;
for(int i=0;i<m;i++){
    cin>>x>>y>>w;
    x--;
    y--;
    g[x].push_back({y,w});
    g[y].push_back({x,w});

}

priority_queue<array<int,4>, vector<array<int,4>>, greater<array<int,4>>>pq;

rep(i,0,n+2){
    rep(j,0,2){
        rep(k,0,2){
            d[i][j][k]=1e18;
        }
    }
}

d[0][0][0]=0;
pq.push({0,0,0,0}); //dist,node,f1,f1

while(!pq.empty()){
    auto [dis,v,mx,mn] = pq.top();
    pq.pop();

    if (dis>d[v][mx][mn]) continue;
    for (auto [u,w]:g[v]){
        for(int i=0;i<=1-mx;i++){
            for(int j=0;j<=1-mn;j++){
                if (d[u][mx|i][mn|j] > d[v][mx][mn]+(1-i+j)*w){
                    d[u][mx|i][mn|j]  = d[v][mx][mn]+(1-i+j)*w;
                    pq.push({d[u][mx|i][mn|j],u,mx|i,mn|j});
                }
            }
        }
    }
}


rep(i,1,n){
    cout<<d[i][1][1]<<" ";
}cout<<endl;






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