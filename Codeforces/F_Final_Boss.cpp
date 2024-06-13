/*
	कर्मण्ये वाधिका रस्ते मा फलेषु कदाचन। मा कर्म फल हेतु र्भूर्मा ते सङ्गोऽस्त्व कर्मणि॥
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define MOD 1000000007

typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;

#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define debug(x)
#endif

void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(lld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}

template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}


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

bool check(int mid, vector<int>&att, vector<int>& cool, int k){
    int tot=0;
    int n= att.size();
    for(int i=0;i<n;i++){
        // cout<<((mid+cool[i]-1)/cool[i])<<" adding -- mid "<<mid<<endl;
        tot += ((mid+cool[i]-1)/cool[i])*att[i];
        if (tot>=k){
            // cout<<mid<<" ... "<<tot<<endl;
            return true;
        }
    }
    // cout<<mid<<" ... "<<tot<<endl;

    if (tot>=k){
        return true;
    }
    return false;
}

void solve()
{
    int n,k;
    cin>>k>>n;
    vector<int> att(n),cool(n);

    for(int i=0;i<n;i++){
        cin>>att[i];
    }
    for(int i=0;i<n;i++){
        cin>>cool[i];
    }

    int l=0;
    int r=5e10;


    // cout<<n<<" "<<k<<endl;
    // for(int i=0;i<n;i++){
    //     cout<<att[i]<<" ";
    // }
    // cout<<endl;
    // for(int i=0;i<n;i++){
    //     cout<<cool[i]<<" ";
    // }
    // cout<<endl;
    // cout<<"*********\n";

    while(r-l>1){
        int mid = (l+r)/2;
        if (check(mid,att,cool,k)){
            r =mid;
        }
        else{
            l=mid;
        }
    }
    cout<<r<<endl;







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