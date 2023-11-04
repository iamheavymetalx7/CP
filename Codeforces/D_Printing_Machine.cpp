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
using ii = pair<int, int>;



void solve()
{
    int n;
    cin>>n;
    vector<pair<int,int>> vec;
    for (int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        vec.pb({a,a+b});
    }

    sort(vec.begin(),vec.end());

    priority_queue<int,vector<int>, greater<>> pq;

    int it=0;
    int ans =0;

    for(int i=0;;i++){
        if(pq.empty()){
            if (it==n) break;
            i = vec[it].first;
        }
        while(it<n && vec[it].first==i){
            pq.push(vec[it++].second);
        }

        while(!pq.empty() && pq.top()<i) pq.pop();
        if(!pq.empty()){
            pq.pop();
            ans++;
        }
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