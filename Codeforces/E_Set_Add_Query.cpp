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
        vector<int> vec(q);
        for(int i=0;i<q;i++){
            cin>>vec[i];
            vec[i]--;
        }

        vector<vector<int>> vv(n+1);
        vector<int> ss;
        set<int> st;

        for(int i=0;i<q;i++){
            vv[vec[i]].push_back(i);
            if (st.count(vec[i])){
                st.erase(vec[i]);
            }
            else{
                st.insert(vec[i]);
            }
            ss.push_back(st.size());
        }


        for(int i=0;i<n;i++){
            cout<<i<<" -- ";
            for(int j=0;j<vv[i].size();j++){
                cout<<vv[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;

        vector<int> cum_sum ={0};
        for(auto x: ss){
            cum_sum.push_back(cum_sum[cum_sum.size()-1]+x);
        }
        for(auto x:cum_sum){
            cout<<x<<" ";
        }
        cout<<endl;
        vector<int> ans(n+1,0);


        for(int i=0;i<n;i++){
            auto iix = vv[i];
            if (iix.size()&1){
                iix.push_back(q);
            }
            for (int j=0;j<iix.size();j+=2){
                int l = iix[j];
                int r = iix[j+1];
                ans[i] += cum_sum[r]-cum_sum[l];
            }
        }

        for(int i=0;i<n;i++){
            cout<<ans[i]<<" ";        }
        cout<<endl;

    
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