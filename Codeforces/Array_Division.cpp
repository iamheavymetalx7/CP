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

bool check(int x, vector<int> &v, int k){
    int c=0;
    int sub=0;
    for(int i=0;i<v.size();i++){
        if(c+v[i]>x){
            sub+=1;
            c=v[i];
        }else{
            c+=v[i];
        }

    }
    sub+=1;
    return sub>k;
}
    
void solve()
{
    int n,k;
    cin>>n>>k;
    vector<int> v(n);
    int sum=0;
    int maxi=0;
    for(auto &x :v){
        cin>>x;
        maxi = max(maxi,x);
        sum+=x;
    }

    int l=maxi-1;
    int r = sum+1;
    while(r-l>1){
        int mid = (l+r)/2;
        if (check(mid,v,k)){
            l=mid;
        }
        else{
            r=mid;
        }
    }
    cout<<r<<endl;

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