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
        vector<string> vec(n);
        for(int i=0;i<n;i++){
            cin>>vec[i];
        }
        vector<int> ch(26,0);
        vector<int> freq;

        
        for (auto x: vec){
            freq.pb(x.size());
            for (auto el: x){
                // cout<<el<<" "<<el-'a'<<endl;
                ch[el-'a']++;

            }
        }

        sort(freq.begin(),freq.end());
        // for (auto el:freq){
        //     cout<<el<<" ";
        // }
        // cout<<endl;
        int cnte=0,cnto=0;

        for(int i=0;i<26;i++){
            // cout<<ch[i]<<" ";
            if (ch[i]%2==1){
                cnto+=1;
                cnte += (ch[i]/2)*2;

            }
            else{
                cnte+=ch[i];
            }
        }
        // cout<<endl;

        // cout<<cnte<<' '<<cnto<<endl;

        int hehe=0;
        int palindromes =0;
        for(auto f:freq){
            if (f%2){
                cnte-=(f/2)*2;
                cnto-=1;
                if (cnte<0 || cnto<0){
                    break;
                }
            }
            else{
                cnte-=f;
                if (cnte<0){
                    break;
                }

            }
            palindromes+=1;
        }

        cout<<palindromes<<endl;
    
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


/*

10
a
ab
abc
abcd
abcde
abcdef
abcdefg
abcdefgh
abcdefghi
abcdefghij



3
xy
tz
abab

*/