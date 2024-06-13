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
    
    //sieve algorithm in cpp
    vector<int> spf(100005,0);

    vector<vector<int>> pref(100005,vector<int>(6,0));


    void sieve(){ 

        for(int i=2;i<100005;i++){
            if(spf[i]==0){
                spf[i]++;
                for(int j=2*i;j<100005;j+=i){
                    spf[j]++;
                }
            }
        }

        for(int i=1;i<100005;i++){
            for(int j=0;j<6;j++){
                pref[i][j] = pref[i-1][j] + (spf[i]==j);
            }
        }



    }




    void solve()
    {   sieve();
        int l,r,q;
        cin>>l>>r>>q;
        int cnt=0;

        cout<<pref[r][q]-pref[l-1][q]<<endl;




    
    
    }
    
    signed main()
    {
        fast
    
        #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
        #endif
        int t; cin>>t; while(t--)
        solve();
        return 0;
    }