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

    int n,q;
    cin>>n>>q;

    vector<vector<int>> arr;

    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        // cout<<s<<endl;
        vector<int> temp;

        for (int j=0;j<n;j++){
            // cout<<s[j]<<endl;
            if (s[j]=='*'){
            temp.push_back(1);}
            else{
                temp.push_back(0);
            }
        }
        arr.pb(temp);
    }
    vector<vector<int>> queries;
    int a,b,c,d;

    for (int i=0;i<q;i++){
        vector<int>temp;
        cin>>a>>b>>c>>d;
        temp.pb(a);
        temp.pb(b);
        temp.pb(c);
        temp.pb(d);

        queries.pb(temp);
    }

    vector<vector<int>> sum;

    sum = vector<vector<int>> (n+1,vector<int>(n+1,0));

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            sum[i][j] = sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+arr[i-1][j-1];
        }
    }

    // for (int i=0;i<=n;i++){
    //     for (int j=0;j<=n;j++){
    //         cout<<sum[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    
    for(auto e: queries){
        a=e[0];
        b=e[1];
        c=e[2];
        d=e[3];
        // cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl;
        int ans = sum[c][d]-sum[a-1][d]-sum[c][b-1]+sum[a-1][b-1];
        cout<<ans<<endl;
    }

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