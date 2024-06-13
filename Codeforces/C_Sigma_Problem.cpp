#include <bits/stdc++.h>
using namespace std;

#define DEBUG(x...) { cout << "(" << #x << ")" << " = ( "; Print(x); }
template <typename T1> void Print(T1 t1) { cout << t1 << " )" << endl; }
template <typename T1, typename... T2>
void Print(T1 t1, T2... t2) { cout << t1 << " , "; Print(t2...); }
 

#define int long long
#define pi (3.141592653589)
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
    int mod = 100000000;
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    sort(v.begin(),v.end());

    int how_many =0;

    for(int i=0;i<n;i++){
        int id = lower_bound(v.begin(),v.end(),mod-v[i])-v.begin();
        int cnt = n-id;
        if(2*v[i]>=mod) cnt--;
        how_many += cnt;
    }

    how_many/=2;
    int ans =0;
    for(int i=0;i<n;i++){
        ans+=(n-1)*v[i];

    }


    ans -= how_many*mod;
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