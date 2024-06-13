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
	    vector<string> vect(n);
        for(int i=0;i<n;i++){
                cin>>vect[i];
        }


        // for(int i=0;i<n;i++){
        //         cout<<vect[i]<<"\n";
        // }

        vector<int> sum;
        for(int i=0;i<n;i++){
            int c=0;
            for (int j=0;j<vect[i].size();j++){
                if (vect[i][j]=='1'){
                    c++;
                }
                
            }
            if (c!=0){
                    sum.push_back(c);
                }
        }

        // for(int i=0;i<sum.size();i++){
        //     cout<<sum[i]<<" ";
        // }
        sort(sum.begin(), sum.end());
        if (sum[0]!=sum[sum.size()-1]){
            cout<<"TRIANGLE"<<endl;
        }
        else{
            cout<<"SQUARE"<<endl;
        }

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