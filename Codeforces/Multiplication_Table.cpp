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
    
bool check(int x, int k, int n){
    int cnt=0;
    for(int i=1;i<=n;i++){
        int add= min(x/i,n);
        if(add==0) break;
        cnt+=add;
    }
    return cnt>=k;
}
void solve()
{
int n;
cin>>n;

int k = (n*n)/2+1;
// cout<<k<<endl;
int lo=0,hi=n*n+1;
while(hi-lo>1){
    int mid =  (lo)+(hi-lo)/2;
    if (check(mid,k,n)){
        hi=mid;
    }
    else{
        lo=mid;
    }
}
cout<<hi<<endl;


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