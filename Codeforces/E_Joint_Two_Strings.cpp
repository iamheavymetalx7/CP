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
    string t;
    cin>>n>>t;

    int m = t.size();

    vector<string> s(n);

    for (auto &e: s){
        cin>>e;
        // cout<<e<<endl;
    }

    vector<int>prefMatch(n);

    for( int i=0;i<n;i++){
        int x=0;

        for(auto e:s[i]){
            if(x==m) break;
            if(t[x]==e) x++;
        }
        prefMatch[i]=x;

    }

    reverse(t.begin(),t.end());

    vector<int> suffMatch(n);

    for(int i=0;i<n;i++){
        int x=0;


        reverse(s[i].begin(),s[i].end());

        for(auto e:s[i]){
            if (x==m) break;
            if(t[x]==e) x++;

        }
        suffMatch[i]=x;
    }

    sort(suffMatch.begin(),suffMatch.end());
    int ans=0;
    for(auto e: prefMatch){
        ans+= n - (lower_bound(suffMatch.begin(), suffMatch.end(),(m-e))-suffMatch.begin());
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