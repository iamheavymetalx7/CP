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
        string s,t;
        cin>>s;
        cin>>t;
        int a =20;
        a+=a+(++a);
        cout<<a<<endl;
        string smallt = "";
        for(int i=0;i<t.size();i++){
            smallt+=tolower(t[i]);
        }
        // cout<<smallt<<endl;
        int j=0;
        bool flag = false;

        for(int i=0;i<s.size();i++){
            // cout<<s[i]<<" "<<t[j]<<endl;
            if (s[i]==smallt[j]){
                j++;

            }
            if (j>=3){
                flag=true;
                break;
            }
            
        }

        if (flag){
            cout<<"Yes\n";
            return;
        }
        // cout<<j<<endl;

        if(j!=2){
            flag=false;
        }
        else if (j==2){
            if (t[t.size()-1]=='X'){
                flag=true;
            }
        }

        if (flag){
            cout<<"Yes\n";
        }
        else{
            cout<<"No\n";
        }
    
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