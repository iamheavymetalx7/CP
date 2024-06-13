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
cin>>n;

vector<int> v[4];
int x,y;
for(int i=0;i<n;i++){
    cin>>x>>y;
    if((x+y)%2==0){
        v[0].push_back(x+y);
        v[1].push_back(x-y);
    }
    else{
        v[2].pb(x+y);
        v[3].pb(x-y);    }
}
int sz;
int ans =0;
for(int i=0;i<4;i++){
    sort(v[i].begin(),v[i].end());
    sz= v[i].size();
    for(int j=0;j<sz;j++){
        ans+=v[i][j]*(2*j+1-sz);
    }
}
cout<<(ans/2)<<endl;

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