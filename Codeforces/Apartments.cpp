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
        int n,m,k;
        cin>>n>>m>>k;
        vector<int> ap(n);
        for(int i=0;i<n;i++){
            cin>>ap[i];
        }

        vector<int> sz(m);
        for(int i=0;i<m;i++){
            cin>>sz[i];
        }
        sort(ap.begin(),ap.end());
        sort(sz.begin(),sz.end());

        // for(int i=0;i<n;i++){
        //     cout<<ap[i]<<" ";
        // }
        // cout<<endl;
        // for(int i=0;i<m;i++){
        //     cout<<sz[i]<<" ";
        // }
        // cout<<endl;


        int i=0,j=0,cnt=0;
        while(i<n && j<m){
            if (sz[j]-k<=ap[i] && ap[i]<=sz[j]+k){
                i++;j++;cnt++;
            }
            else if(sz[j]+k<ap[i]){
                j++;
            }
            else{
                i++;
            }


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