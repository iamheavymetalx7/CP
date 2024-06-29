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
    int n;
    string s;
    cin>>n;
    cin>>s;
    map<char,int> mp;
    for(auto &x:s){
        mp[x]++;
    }
    int ans = n*(n+1);
    ans/=2;
    int val=1;
    bool f=false;
    for(auto [k,v]:mp){
        if(v>1){
            f=true;
        val*=v;
        }

    }
    cout<<ans-(f?val:0)<<endl;


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