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
void solve()
{
    int n,k;
    cin>>n>>k;
    vector<int> v(n+1);
    int x;
    rep(i,1,n+1){
        cin>>x;
        v[x]=i;
    }

    int ans =n-1;
    set<int> s;
    rep(i,1,k+1){
        s.insert(v[i]);
    }
    auto mini = *s.begin();
    auto maxi = *s.rbegin();
    ans = min(ans,maxi-mini);
    rep(i,k+1,n+1){
        s.erase(v[i-k]);
        s.insert(v[i]);
        auto mini = *s.begin();
        auto maxi = *s.rbegin();
        ans = min(ans,maxi-mini);
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