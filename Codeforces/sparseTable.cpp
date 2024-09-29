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
    




void buildTable(nums,n){
    int n = nums.size();
    int logn = log2(n)+1;

    for(int i=0;i<n;i++){
        table[i][0] = nums[i];
    }

    for(int j=1;j<logn;j++){
        for(int i=0;i+(1<<j)<=n;i++){
            table[i][j] = min(table[i][j-1], table[i+(1<<(j-1))][j-1])
        }
    }

    int kk = L-R+1;
    int k = log2(k);

    ans = min(table[L][k], table[R-(1<<k)+1][k])
    cout<<ans<<endl;
}
void solve()
{


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