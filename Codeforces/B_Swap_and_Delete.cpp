#include <bits/stdc++.h>
using namespace std;

#define DEBUG(x...) { cout << "(" << #x << ")" << " = ( "; Print(x); }
template <typename T1> void Print(T1 t1) { cout << t1 << " )" << endl; }
template <typename T1, typename... T2>
void Print(T1 t1, T2... t2) { cout << t1 << " , "; Print(t2...); }
 

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
    string s;
    cin>>s;
    int n=s.size();
    map<char,int> mp;
    for(int i=0;i<s.size();i++){
        mp[s[i]]++;
    }

    int v1 = mp['1'];
    int v0 = mp['0'];

    v1 = v1-(v1>v0?v1-v0:0);
    v0 = v0-(v0>v1?v0-v1:0);

    string t="";
    int i=0;
    int del =0;
    while(i<n){
        if (s[i]=='0' && v1>0){
            i++;
            v1-=1;

        }
        else if (s[i]=='1' && v0>0){
            i++;
            v0-=1;
        }
        else{
            break;
        }
        
    }
    cout<<n-i<<endl;


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