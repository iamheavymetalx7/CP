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


    /*
    k+(n-1)*(k-1) = k-1+1+(n-1)*(k-1) = n*(k-1)+1+[p]

    p -> where we have more than k
    
    
    */
    int n,k;
    cin>>n>>k;
    vector<int> v(n);
    rep(i,0,n){
        cin>>v[i];
    }
    sort(v.begin(),v.end());
    reverse(v.begin(),v.end());

    int lst = v.back(),cnt=1;
    v.pop_back();
    while(!v.empty()&&lst==v.back()){
        v.pop_back();
        cnt++;

    }

    while(!v.empty()){
        int delta = v.back()-lst;
        if(k<delta*cnt) break;
        k-=delta*cnt;
        lst = v.back();
        while(!v.empty() && lst == v.back()){
            v.pop_back();
            cnt++;
        }
    }
    lst += k/cnt;
    k%=cnt;
    cnt-=k;

    cout<<n*lst-cnt+1<<endl;


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