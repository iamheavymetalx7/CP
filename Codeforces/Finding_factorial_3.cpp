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
        n+=1;
        bool flag=false;
        long long curr =1;
        for(int i=1;i<=1000;i++){
            curr*=i;
            if(curr==n){
                flag=true;
                break;
            }
            else if(curr>n){
                flag=false;
                break;
            }
        }
        if(flag){
            cout<<"Yes\n";
        }
        else{
            cout<<"No\n";
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