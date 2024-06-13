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

    bool check(string a, string org){
        int x=org.size();
        int diff =0;
        for(int i=0;i<x;i++){
            if (org[i]!=a[i]){
                diff+=1;
            }
            
        }
        if (diff<=1){
            return true;
        }
        return false;
    }
    
    void solve()
    {
        int n;
        cin>>n;
        string s;
        cin>>s;

        vector<int>arr;
        for(int i=1;i<=sqrt(n);i++){
            if (n%i==0){
                if (n/i==i){
                    arr.push_back(i);
                }
                else{
                    arr.push_back(n/i);
                    arr.push_back(i);
                }
            }
        }

        sort(arr.begin(),arr.end());
        int m= arr.size();
        int final = 2e5+20;
        // for(int i=0;i<m;i++){
        //     cout<<arr[i]<<" ";
        // }
        // cout<<endl;

        for(int i=0;i<m;i++){
            string sub = s.substr(0,arr[i]);
            string news;
            int siuu = n/arr[i];
            for(int i=0;i<siuu;i++){
                news+=sub;
            }
            if (check(news,s)){
                final = min(final,arr[i]);

            }
        }

        reverse(s.begin(),s.end());

        for(int i=0;i<m;i++){
            string sub = s.substr(0,arr[i]);
            string news;
            int siuu = n/arr[i];
            for(int i=0;i<siuu;i++){
                news+=sub;
            }
            if (check(news,s)){
                final = min(final,arr[i]);

            }
        }

        cout<<final<<endl;
        




    
    
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