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


struct SegTree {
public:
 
    SegTree (int _n) : n (_n) {
        tree.resize(4*n, 0);
    }
    
    int query (int x, int y) {
        return query (x, y, 0, n-1, 0);
    }
    
    void update (int ind, int val) {
        update (ind, val, 0, n-1, 0);
    }
 
private:
    
    vector<int> tree;
    int n;
    
    int query (int x, int y, int l, int r, int i) {
        if (r < x || l > y) return 0;
        if (l >= x && r <= y) return tree[i];
        
        int m = (l+r) >> 1;
        return (
            query (x, y, l, m, i*2+1) +
            query (x, y, m+1, r, i*2+2)
        );
    }
    
    void update (int ind, int val, int l, int r, int i) {
        if (l == r) {
            tree[i] += val;
            return;
        }
        
        int m = (l+r) >> 1;
        if (m >= ind) update (ind, val, l, m, i*2+1);
        else update (ind, val, m+1, r, i*2+2);
        
        tree[i] = tree[i*2+1] + tree[i*2+2];
    }
};
    
void solve()
{
    int n;
    cin>>n;
    vector<int> arr(n);
    for(auto &x:arr){
        cin>>x;
    }

    // debug(v);
    vector<pair<int,int>> element_and_ind;
    for(int i=0;i<n;i++)
    {
        element_and_ind.push_back({arr[i],i});
    }

    sort(element_and_ind.begin(), element_and_ind.end());

    map<int,int> position;
    for(int j=0;j<n;j++){
        position[element_and_ind[j].ff] =j;
    }

    SegTree tree(n);

    ll result =0;

    for(int j=0;j<n;j++){
        int pos = position[arr[j]];
        ll greater_in_left = tree.query(pos+1,n-1);
        ll smaller_in_left= j-greater_in_left;

        ll smaller_in_right = pos-smaller_in_left;
        ll greater_in_right = (n-1-pos)-greater_in_left;

        result += greater_in_left * smaller_in_right;

        tree.update(pos,1);

    }
    cout<<result<<endl;


 

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