#include <bits/stdc++.h>
using namespace std;

#define DEBUG(x...) { cout << "(" << #x << ")" << " = ( "; Print(x); }
template <typename T1> void Print(T1 t1) { cout << t1 << " )" << endl; }
template <typename T1, typename... T2>
void Print(T1 t1, T2... t2) { cout << t1 << " , "; Print(t2...); }
 
typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;

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
    
void solve()
{
    int n,target;
    cin>>n>>target;
    vector<ii> arr;
    for(int i=1;i<=n;i++){
        ii p;
        int x;
        cin>>x;
        p.ff = x;
        p.ss = i;
        arr.push_back(p);
    }
    // for(int i=0;i<n;i++){
    //     cout<<arr[i].ff<<" "<<arr[i].ss<<endl;
    // }
    sort(arr.begin(), arr.end());
    for(int i=0;i<n;i++){
        int l=0,r=n-1;
        int tgt = target - arr[i].ff;
        while(l!=r){
            int val = arr[r].ff+arr[l].ff;
            if (l!=i && r!=i && val== tgt){
            cout<<arr[i].ss<<" "<<arr[l].ss<<" "<<arr[r].ss<<endl;
            return ;
            }
            else if (val > tgt ){
                r--;
            }
            else{l++;
            }
        }
    }

    cout<<"IMPOSSIBLE \n";


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