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

int check(vector<int>&a , vector<int>&b, vector<int>&c){
    int idxa=-1;
    int n =a.size();
    int maxi =0;
    for(int i=0;i<n;i++){
        if (maxi<=a[i]){
            if (maxi ==a[i]){
                if (b[idxa]>b[i]){
                    idxa=i;
                }
            }
            else{
                idxa=i;
            }
            maxi = a[i];
        }
    }
    int idxb =-1;
    int maxib=0;
    for(int i=0;i<n;i++){
        if (i==idxa) continue;
        if (maxib<=b[i]){
            if (maxib ==b[i]){
                if (c[idxb]>c[i]){
                    idxb=i;
                }
            }
            else{
                idxb=i;
            }
            maxib = b[i];
        }
    }
    int maxic=0;
    int idxc=-1;
    for(int i=0;i<n;i++){
        if(i==idxa || i==idxb)  continue;
        maxic=  max(maxic,c[i]);
    }

    return (maxi+maxib+maxic);

}
    
void solve()
{
    int n;
     cin>>n;
    vector<int> a(n),b(n),c(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        cin>>b[i];
    }
    for(int i=0;i<n;i++){
        cin>>c[i];
    }

    int ans =0;

    ans = max(ans,check(a,b,c));
    ans = max(ans,check(a,c,b));
    ans = max(ans,check(b,a,c));
    ans = max(ans,check(b,c,a));
    ans = max(ans,check(c,a,b));
    ans = max(ans,check(c,b,a));
    cout<<ans<<endl;


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