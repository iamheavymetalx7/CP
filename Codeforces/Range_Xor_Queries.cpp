// #include <bits/stdc++.h>
//     using namespace std;
//     #define int long long
//     #define pi (3.141592653589)
//     #define mod 1000000007
//     #define float double
//     #define ff first
//     #define ss second
//     #define mk make_pair
//     #define pb push_back
//     #define rep(i, start, end) for (int i = start; i < end; i++)
//     #define ld long double
//     #define fast ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
//     int inf = 1000000000000000000;
//     using ii = pair<int, int>;
    
//     void solve()
//     {
//         int n,q;
//         cin>>n>>q;
        
//         int maxN = 19;

//         vector<vector<int>> sparse(n,vector<int>(maxN,0));

//         vector<int> v(n);
//         rep(i,0,n){
//             cin>>v[i];
//             sparse[i][0] = v[i];
//         }

//         for(int k=1;k<maxN;k++){
//             for(int i=0;i+(1<<k)<n+1;i++){
//                 sparse[i][k] = sparse[i][k-1]^sparse[i+(1<<(k-1))][k-1];
//             }
//         }

//         rep(i,0,q){
//             int l,r;
//             cin>>l>>r;
//             l-=1;
//             r-=1;
//             int kk = log2(r-l+1);

//             int ans = sparse[l][kk]^sparse[r-(1<<kk)+1][kk];
//             cout<<ans<<endl;
//         }



     
     
     
//     }
    
//     signed main()
//     {
//         fast
//         // int t; cin>>t; while(t--)
    
//         #ifndef ONLINE_JUDGE
//         freopen("input.txt","r",stdin);
//         freopen("output.txt","w",stdout);
//         #endif
//         solve();
//         return 0;
//     }

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

     vector<int> vec(n);
     rep(i,0,n){
        cin>>vec[i];
     }

     vector<int> pref(n+1,0);
     pref[1] = vec[0];

     for(int i=2;i<pref.size();i++)
     {
        pref[i]=pref[i-1]^vec[i-1];
     }

     for(int i=0;i<q;i++){
        int l,r;
        cin>>l>>r;
        int ans = pref[r]^pref[l-1];
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