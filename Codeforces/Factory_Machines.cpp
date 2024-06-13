#include <bits/stdc++.h>
using namespace std;

#define DEBUG(x...) { cout << "(" << #x << ")" << " = ( "; Print(x); }
template <typename T1> void Print(T1 t1) { cout << t1 << " )" << endl; }
template <typename T1, typename... T2>
void Print(T1 t1, T2... t2) { cout << t1 << " , "; Print(t2...); }
 

#define int long long int
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

bool check(int mid, int k, vector<int>& v){
    int cnt=0;
    for(auto &x:v){
        cnt+=mid/x;
        if (cnt>=k){
            break;
        }
    }
//    cout<<cnt<<" "<<mid<<" "<<k<<endl;
   return cnt<k;
}
    
void solve()
{
    int n,k;
    cin>>n>>k;
    vector<int> vec(n);
    for(auto &x:vec){
        cin>>x;
    }

    int l=0,r=1e18+1;
    
    while (r-l > 1){
        int mid = (l+r)/2;
        if (check(mid,k,vec)){
            l=mid;
        }
        else{

        r=mid;

        }
    }

    cout<<r<<endl;


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