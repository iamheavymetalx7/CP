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
        int n,c,d;
        cin>>n>>c>>d;
        int sz = n*n;
        vector<int> vec(sz);
        for(int i=0;i<sz;i++){
            cin>>vec[i];
        }
        sort(vec.begin(),vec.end());
        int x = vec[0];
        vector<int> other,first_row;
        other.push_back(x);
        first_row.push_back(x);
        
        for(int i=1;i<n;i++){
            x = x+d;
            other.push_back(x);
            first_row.push_back(x);
        }

        for(int i=0;i<n;i++){
            x =first_row[i];
            // cout<<x<<"  first rown \n";
            for(int j=1;j<n;j++){
                x = x+c;
                other.push_back(x);
            }
        }

        sort(other.begin(),other.end());

        bool f =true;

        // for(int i=0;i<sz;i++){
        //     cout<<other[i]<<" "<<vec[i]<<endl;
        // }
        // cout<<endl;

        for(int i=0;i<sz;i++){
            if (other[i]!=vec[i]){
                f=false;
                break;
            }
        }
        if (f){
            cout<<"YES\n";
        }
        else{
            cout<<"NO\n";
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