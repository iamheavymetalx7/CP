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

    vector<pair<int,int>> pos(n);

    for(int i=0;i<n;i++){
        pos[i] = {vec[i],i};
    }

    sort(pos.begin(),pos.end());

    // for(int i=0;i<n;i++){
    //     cout<<pos[i].ff<<" "<<pos[i].ss<<endl;

    // }
    // cout<<endl;

    int curr=-1;
    int cnt=1;
    for(int i=0;i<n;i++){
        if (curr>pos[i].ss){
            cnt++;
        }
        curr = pos[i].ss;

        
    }

    cout<<cnt<<endl;

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