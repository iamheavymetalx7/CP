#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;

#define DEBUG(x...) { cout << "(" << #x << ")" << " = ( "; Print(x); }
template <typename T1> void Print(T1 t1) { cout << t1 << " )" << endl; }
template <typename T1, typename... T2>
void Print(T1 t1, T2... t2) { cout << t1 << " , "; Print(t2...); }
 


#define debug(x)                                                               \
    cout << #x << " ";                                                         \
    _print(x);                                                                 \
    cout << endl;

void _print(ll t) { cout << t; }
void _print(int t) { cout << t; }
void _print(string t) { cout << t; }
void _print(char t) { cout << t; }
void _print(lld t) { cout << t; }
void _print(double t) { cout << t; }
void _print(ull t) { cout << t; }

template <class T, class V> void _print(pair<T, V> p);
template <class T> void _print(vector<T> v);
template <class T> void _print(set<T> v);
template <class T, class V> void _print(map<T, V> v);
template <class T> void _print(multiset<T> v);
template <class T, class V> void _print(pair<T, V> p) {
    cout << "{";
    _print(p.ff);
    cout << ",";
    _print(p.ss);
    cout << "}";
}
template <class T> void _print(vector<T> v) {
    cout << "[ ";
    for (T i : v) {
        _print(i);
        cout << " ";
    }
    cout << "]";
}
template <class T> void _print(set<T> v) {
    cout << "[ ";
    for (T i : v) {
        _print(i);
        cout << " ";
    }
    cout << "]";
}
template <class T> void _print(multiset<T> v) {
    cout << "[ ";
    for (T i : v) {
        _print(i);
        cout << " ";
    }
    cout << "]";
}
template <class T, class V> void _print(map<T, V> v) {
    cout << "[ ";
    for (auto i : v) {
        _print(i);
        cout << " ";
    }
    cout << "]";
}

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
    

int check(int x, vector<int> & pref){
    int val = lower_bound(pref.begin(),pref.end(),x)-pref.begin();
    return val;
}

void solve()
{
int n;
cin>>n;
vector<int> vec(n);
for(auto &x:vec){
    cin>>x;
}
vector<int>pref(n,0);
pref[0] = vec[0];
for(int i=1;i<n;i++){
    pref[i] = pref[i-1]+vec[i];
}

// debug(pref)

int q;
cin>>q;
vector<int> queries(q,0);
for(auto& qq: queries){
cin>>qq;
}

// debug(queries)

for(auto x: queries){
    int ans = check(x,pref);
    cout<<ans+1<<endl;
}

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