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

    int n,k;
    cin>>n>>k;


    vector<int> vec(n);
    for(int i=0;i<n;i++){
        cin>>vec[i];
    }

    sort(vec.begin(),vec.end());



    int i=0;
    while(i<n){
        if (vec[i]<=k){
            i++;
        }
        else{
            break;
        }
    }

    int ans = (k*(k+1))/2;
    int prev=0;
    for(int j=0;j<i;j++){
        if (prev!=vec[j]){
            ans-=vec[j];
            prev=vec[j];
        }
    }
    cout<<ans<<endl;
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