#include <bits/stdc++.h>
using namespace std;
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

void solve()
{
    int n;
    string s;
    cin >>n;
    cin>>s;

    vector<int> cnt(10);
    vector<int> cnt2(10);

    for (auto e:s) cnt[e-'0']++;

    int ans =0;
    for (int i=0;i<=1e7;i++){
        int x;
        x=i*i;
        fill(cnt2.begin(),cnt2.end(),0);

        string t = to_string(x);

        for(auto e: t) cnt2[e-'0']++;
        cnt2[0] = max(cnt[0],cnt2[0]);
        if (cnt==cnt2) ans++;
    }

    cout<<ans<<"\n";
    

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