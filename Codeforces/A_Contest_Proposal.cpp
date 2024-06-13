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
    
    int check(vector<int> &a,vector<int> &b){
        int n = a.size();

        for(int i=0;i<n;i++){
            if(a[i]>b[i]){

                return i;
            }
        }
        return n+1;
    }
    void solve()
    {
        int n;
        cin>>n;
        vector<int> a(n),b(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        for(int i=0;i<n;i++){
            cin>>b[i];
        }
        int cnt=0;
        int jj=0;

        while(jj<100){

                int ii = check(a,b);

                if (ii==n+1){break;}
                a.push_back(b[ii]);
                sort(a.begin(),a.end());
                a.pop_back();
                cnt++;
                jj++;

        }

        cout<<cnt<<endl;

    
    
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