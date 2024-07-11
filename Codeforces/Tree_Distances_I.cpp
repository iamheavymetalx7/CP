#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;

#define debug(x) cout << #x <<" "; _print(x); cout << endl;

void _print(ll t) {cout << t;}
void _print(int t) {cout << t;}
void _print(string t) {cout << t;}
void _print(char t) {cout << t;}
void _print(lld t) {cout << t;}
void _print(double t) {cout << t;}
void _print(ull t) {cout << t;}

template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cout << "{"; _print(p.ff); cout << ","; _print(p.ss); cout << "}";}
template <class T> void _print(vector <T> v) {cout << "[ "; for (T i : v) {_print(i); cout << " ";} cout << "]";}
template <class T> void _print(set <T> v) {cout << "[ "; for (T i : v) {_print(i); cout << " ";} cout << "]";}
template <class T> void _print(multiset <T> v) {cout << "[ "; for (T i : v) {_print(i); cout << " ";} cout << "]";}
template <class T, class V> void _print(map <T, V> v) {cout << "[ "; for (auto i : v) {_print(i); cout << " ";} cout << "]";}

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
  
    int n;
    cin>>n;

    vector<vector<int>> adj(n+1);

    for(int i=0;i<n-1;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> in(n+1,0), out(n+1,0);

    function<void(int,int)> dfs =[&](int node,int par){
        in[node]=0;
        // cout<<node<<" "<<par<<endl;
        for(auto child: adj[node] ){
            if (child==par) continue;
            dfs(child,node);
            in[node] = max(in[node],1+in[child]);
        }
    };

    dfs(1,0);

    function<void(int,int)> dfs2 =[&](int node, int par){
        int mx1(-1), mx2(-1);

        for(int child :adj[node]){
            if(child==par) continue;
            if (in[child]>=mx1) mx2=mx1, mx1 =in[child];
            else if(in[child]>mx2) mx2 =in[child];
        }

        for(auto v: adj[node]){
            if(v==par)continue;
            int use =mx1;
            if (mx1==in[v]) use=mx2;

            out[v] = max(use+2,out[node]+1);
            dfs2(v,node);
        }
    };

    // debug(in);
    dfs2(1,0);
    // debug(out);
    for(int i=1;i<=n;i++){
        cout<< max(in[i],out[i])<<" ";
    }
    cout<<endl;


}

signed main()
{
    fast

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    // int t; cin>>t; while(t--)
    solve();
    return 0;
}