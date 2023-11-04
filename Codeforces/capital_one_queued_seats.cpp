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
    vector<int> vec(n);
    for(int i=0;i<n;i++){
        cin>>vec[i];
    }
    // for(int i=0;i<n;i++){
    //     cout<<vec[i]<<" ";
    // }
    vector<int> final(n,0);

    // int val = 1e5;
    set<int> seen;
    for(int i=1;i<=(2*n);i++){
        seen.insert(i);
    }

    queue<pair<int,pair<int,bool>>> q;
    for(int i=0;i<n;i++){
        q.push({vec[i],{i,false}});
    }

    set<int> onemore;

    while(!q.empty())
{
    auto x = q.front();
    q.pop();
    auto it = seen.find(x.first);
    if (it==seen.end()){
        if (x.second.second==true){
            auto xxx = seen.lower_bound(x.first);
            final[x.second.first]=*xxx;
            seen.erase(xxx);

        }
        else{

        q.push({x.first+1,{x.second.first,true}});
        }



    }
    else{
        seen.erase(it);
        final[x.second.first]=x.first;

    }
}

for( int i=0;i<n;i++){
    cout<<final[i]<<" ";

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


/*

5
1 3 3 2 2


5
1 2 3 2 4

*/