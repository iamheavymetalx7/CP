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
        set<string> st;
        st.insert("ABC316"); st.insert("ABC000");
         
        string t;
        cin>>t;
        
        string num = "";
        for(int i=3;i<6;i++){
            num+=t[i];
        }
        // cout<<num<<endl;
        if (st.count(t)){
            cout<<"No"<<endl;
            return;
        }
        if (stoi(num)>=350){
            cout<<"No"<<endl;
            return;
        }
        cout<<"Yes"<<endl;
        return;
    
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