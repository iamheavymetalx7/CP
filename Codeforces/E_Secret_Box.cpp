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
int x,y,z,k;
cin>>x>>y>>z>>k;
// DEBUG(x,y,z,k);
int ans =0;
for(int i=1;i<=x;i++){
    if (k%i) continue; // if (k%i) is not zero, skip the rest of the loop;
    for(int j=1;j<=y;j++){
        if (k%(i*j)) continue; // if (k%(i*j)) is not zero, skip the rest of the loop
        int updz = k/(i*j);
        if (1<=updz && updz<=z){
            ans = max(ans, (x-i+1)*(y-j+1)*(z-updz+1));

        }
    }
}
cout<<ans<<endl;



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