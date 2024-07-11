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
    // cout<<n<<endl;
    vector<vector<int>> adj(n+1);

    for(int i=0;i<n-1;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    // debug(adj);
    vector<int> cnt(n+1,0);
    vector<long long> subAns(n+1,0), ans(n+1,0);

    auto addChild =[&](int node, int child){
        cnt[node]+=cnt[child];
        subAns[node] += subAns[child]+cnt[child];
    };

    auto removeChild =[&](int node, int child){
        subAns[node] -= subAns[child]+cnt[child];
        cnt[node] -= cnt[child];

    };

    auto changeRoot =[&](int node, int child){
        removeChild(node, child);
        addChild(child, node);
    };

    function<void(int,int)> dfs =[&](int node,int parent){
        cnt[node]=1;
        subAns[node]=0;

        for(auto child: adj[node]){
            if (child==parent) continue;
            dfs(child,node);
            // adding the contribution of nodes of child subtrees
            addChild(node, child);
        }
    };
    
    function<void(int,int)> reRoot =[&](int node,int parent){
        ans[node] = subAns[node];
        for(auto child: adj[node]){
            if(child ==parent) continue;
            changeRoot(node,child);
            reRoot(child,node);
            changeRoot(child,node);

        }
    };

    dfs(1,0);
    // debug(cnt);
    // debug(subAns);
    reRoot(1,0);
    // debug(cnt);
    // debug(subAns);
    // debug(ans);
    for(int i=1;i<=n;i++){
        cout<<ans[i]<<" ";
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