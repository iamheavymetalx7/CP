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
    int n,a,b,c;
    cin>>n>>a>>b>>c;

    vector<vector<int>> d(n,vector<int>(n));

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>d[i][j];
        }
    }

    // for (int i=0;i<n;i++){
    //     for (int j=0;j<n;j++){
    //         cout<<d[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }

    vector<int> dis0(n,inf);
    vector<int> dis1(n,inf);

    dis0[0]=0;
    dis1[0]=0;

    priority_queue<vector<int>, vector<vector<int>>,greater<vector<int>>> pq;

    pq.push({0,0,1});
    pq.push({0,0,0});

    // time, place, mode = car/train (0/1)

    while(!pq.empty()){
        auto vec = pq.top();
        // cout<<vec[0]<<" "<<vec[1]<<" "<<vec[2]<<endl;

        pq.pop();

        if (vec[2]==0){
        if(dis0[vec[1]]!=vec[0]){
            continue;
        }
        // cout<<"car"<<endl;

        for(int i=0;i<n;i++){
            if (dis0[i]>vec[0]+d[vec[1]][i]*a){
                dis0[i] = vec[0]+d[vec[1]][i]*a;
                // cout<<dis0[0]<<" "<<i<<" "<<"0"<<endl;
                pq.push({dis0[i],i,0});
            }
        }

        for(int i=0;i<n;i++){
            if (dis1[i]>vec[0]+d[vec[1]][i]*b+c){
                dis1[i] = vec[0]+d[vec[1]][i]*b+c;
                pq.push({dis1[i],i,1});
            }
        }
        }
        else{
            // cout<<"traintrain"<<endl;
            if(dis1[vec[1]]!=vec[0]){
                        continue;
        }   
        // cout<<"train"<<endl;

        for(int i=0;i<n;i++){
            if (dis1[i]>vec[0]+d[vec[1]][i]*b+c){
                dis1[i] = vec[0]+d[vec[1]][i]*b+c;
                pq.push({dis1[i],i,1});
            }
        }
        }

    }

    cout<<min(dis0[n-1],dis1[n-1])<<endl;


    

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