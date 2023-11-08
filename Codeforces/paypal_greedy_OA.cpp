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
    {	int n;
        cin>>n;

        vector<int> vec(n);

        for(int i=0;i<n;i++){
            cin>>vec[i];
        }

        int maxMin = vec[n-1];
        int ops =0;

        for(int i=n-2;i>=0;i--){
            if (vec[i]>maxMin){
                int part = ceil(vec[i]/double(maxMin));
                ops+=part-1;
                maxMin = vec[i]/part;
            }
            else{
            maxMin =vec[i];
            }
        }
        cout<<ops<<endl;

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