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
    int n,m;
    cin>>n>>m;
    vector<vector<char>> vec(n,vector<char>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>vec[i][j];
    }
    }
    int assigned =1;
    vector<vector<int>> dire = {{1,0},{0,1},{-1,0},{0,-1}};
    vector<vector<int>> vis(n,vector<int> (m,0));

    // Use std::function to declare dfs
    function<void(int, int, int)> dfs = [&](int i, int j, int assign) {
        vis[i][j] = assign;
        for (int k=0;k<4;k++){
            int newi = i+dire[k][0];
            int newj = j+dire[k][1];
            if (newi<0 || newj<0 || newi>=n || newj>=m || vis[newi][newj] || vec[newi][newj]=='.'){
                continue;
            }
            dfs(newi,newj, assign);
        }

    };

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if (!vis[i][j] && vec[i][j]=='#'){
                // cout<<i<<" "<<j<<" .. "<< assigned<<endl;
                dfs(i,j,assigned);
                assigned++;
            }
        }
    }

    // debug(vis);
    //map me dalta hu kis component k kitne element present h
    map<int,int> mp;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            mp[vis[i][j]]++;
        }
    }
    // rows k lie kaam krenge
    int maxi =0;
 for(int i=0;i<n;i++) {
        set<int> st;
        int sp = 0;
        for(int j=0;j<m;j++) {
            sp += (vec[i][j] == '.');
            if(vis[i][j] != 0) {
                st.insert(vis[i][j]);
            }
            if(i > 0 && vis[i - 1][j] != 0) {
                st.insert(vis[i - 1][j]);
            }
            if(i < n - 1 && vis[i + 1][j] != 0) {
                st.insert(vis[i + 1][j]);
            }
        }
        int res = sp;
        for(auto k : st) res += (mp[k]);
        maxi = max(maxi, res);
    }
 for(int j=0;j<m;j++) {
        set<int> st;
        int sp = 0;
        for(int i=0;i<n;i++) {
            sp += (vec[i][j] == '.');
            if(vis[i][j] != 0) {
                st.insert(vis[i][j]);
            }
            if(j > 0 && vis[i][j - 1] != 0) {
                st.insert(vis[i][j - 1]);
            }
            if(j < m - 1 && vis[i][j + 1] != 0) {
                st.insert(vis[i][j + 1]);
            }
        }
        int res = sp;
        for(auto k : st) res += (mp[k]);
        maxi = max(maxi, res);
    }
    cout<<maxi<<endl;
 

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