// ███████╗██╗███╗   ██╗██╗███████╗██╗  ██╗    ██╗    ██╗██╗  ██╗ █████╗ ████████╗    ██╗   ██╗ ██████╗ ██╗   ██╗    ███████╗████████╗ █████╗ ██████╗ ████████╗    ██╗
// ██╔════╝██║████╗  ██║██║██╔════╝██║  ██║    ██║    ██║██║  ██║██╔══██╗╚══██╔══╝    ╚██╗ ██╔╝██╔═══██╗██║   ██║    ██╔════╝╚══██╔══╝██╔══██╗██╔══██╗╚══██╔══╝    ██║
// █████╗  ██║██╔██╗ ██║██║███████╗███████║    ██║ █╗ ██║███████║███████║   ██║        ╚████╔╝ ██║   ██║██║   ██║    ███████╗   ██║   ███████║██████╔╝   ██║       ██║
// ██╔══╝  ██║██║╚██╗██║██║╚════██║██╔══██║    ██║███╗██║██╔══██║██╔══██║   ██║         ╚██╔╝  ██║   ██║██║   ██║    ╚════██║   ██║   ██╔══██║██╔══██╗   ██║       ╚═╝
// ██║     ██║██║ ╚████║██║███████║██║  ██║    ╚███╔███╔╝██║  ██║██║  ██║   ██║          ██║   ╚██████╔╝╚██████╔╝    ███████║   ██║   ██║  ██║██║  ██║   ██║       ██╗
// ╚═╝     ╚═╝╚═╝  ╚═══╝╚═╝╚══════╝╚═╝  ╚═╝     ╚══╝╚══╝ ╚═╝  ╚═╝╚═╝  ╚═╝   ╚═╝          ╚═╝    ╚═════╝  ╚═════╝     ╚══════╝   ╚═╝   ╚═╝  ╚═╝╚═╝  ╚═╝   ╚═╝       ╚═╝
//                                                                                                                                                                   

#include<iostream>
#include<iterator>
#include<algorithm>
#include<bits/stdc++.h>

using namespace std;

typedef  long long int ll;
typedef  long double ld;
typedef std::vector<int> vi;
typedef std::vector<ll> vll;
typedef std::vector<ld> vld;
typedef std::vector<std::vector<ll> > vvll;
typedef std::vector<std::vector<ld> > vvld;
typedef std::vector<std::vector<std::vector<ll> > > vvvll;
typedef std::vector<string> vstr;
typedef std::vector<bool> vbl;
typedef std::vector<std::pair<ll,ll> > vpll;
typedef std::pair<ll,ll> pll;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ordered_set     tree<ll, null_type,less<ll>, rb_tree_tag,tree_order_statistics_node_update>

#define fast            ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define in(n)           long long int n;   cin >> n
#define inarr(n, arr)   vector<long long int>   arr(n); for(long long int i = 0; i < n; ++i)    cin >> arr[i]
#define instr(s)        string s;   cin >> s
#define pb              push_back
#define nl              "\n"
#define all(c)          (c).begin(),(c).end()
#define iotam1            cout<<-1<<nl
#define cty             cout<<"YES"<<nl
#define ctn             cout<<"NO"<<nl
#define lmax            LLONG_MAX
#define lmin            LLONG_MIN
#define sz(v)           (v).size()
#define deci(n)         fixed<<setprecision(n)
#define c(x)            cout<<(x)
#define csp(x)          cout<<(x)<<" "
#define c1(x)           cout<<(x)<<nl
#define c2(x,y)         cout<<(x)<<" "<<(y)<<nl
#define c3(x,y,z)       cout<<(x)<<" "<<(y)<<" "<<(z)<<nl
#define c4(a,b,c,d)     cout<<(a)<<" "<<(b)<<" "<<(c)<<" "<<(d)<<nl
#define c5(a,b,c,d,e)   cout<<(a)<<" "<<(b)<<" "<<(c)<<" "<<(d)<<" "<<(e)<<nl
#define c6(a,b,c,d,e,f) cout<<(a)<<" "<<(b)<<" "<<(c)<<" "<<(d)<<" "<<(e)<<" "<<(f)<<nl

#define f(i_itr,a,n) for(ll i_itr=a; i_itr<n; i_itr++)
#define rev_f(i_itr,n,a) for(ll i_itr=n; i_itr>=a; i_itr--)
#define arri(n, arr) for(ll i_itr=0; i_itr<n; i_itr++) cin>>arr[i_itr]
#define a_arri(n, m, arr) for(ll i_itr=0; i_itr<n; i_itr++) for (ll j_itr=0; j_itr<m; j_itr++) cin>>arr[i_itr][j_itr]
#define pb push_back
#define fi first
#define se second
#define print(vec,a,b) for(ll i_itr=a;i_itr<b;i_itr++) cout<<vec[i_itr]<<" ";cout<<"\n";
#define input(vec,a,b) for(ll i_itr = a;i_itr<b;i_itr++) cin>>vec[i_itr];
#define ms(a,val) memset(a,val,sizeof(a))
#define loopz(vec) for(auto z: vec)


const ll mod = 1000000007;
const long double pi=3.14159265358979323846264338327950288419716939937510582097494459230;

ll pct(ll x) { return __builtin_popcount(x); } // # of set bits
ll poww(ll a, ll b) { ll res=1; while(b) { if(b&1)	res=(res*a); a=(a*a); b>>=1; } return res; }
ll modI(ll a, ll m=mod) { ll m0=m,y=0,x=1;  if(m==1) return 0;  while(a>1)  { ll q=a/m; ll t=m;  m=a%m;  a=t; t=y; y=x-q*y;  x=t; } if(x<0) x+=m0; return x;}
ll powm(ll a, ll b,ll m=mod) {ll res=1;	while(b) {	if(b&1)	res=(res*a)%m;	a=(a*a)%m; b>>=1;	}	return res;}
ll nCrMod(ll n,ll r,ll p=mod){   if( r < 0 ) return 1;   if (n < r)  return 0;   if (r == 0) return 1;   ll fac[n + 1];  fac[0] = 1; for (int i = 1; i <= n; i++)    fac[i] = (fac[i - 1] * i) % p;  return (fac[n] * modI(fac[r]) % p * modI(fac[n - r]) % p) % p;}
ll ceilDiv(ll a, ll b){ if(a%b) return a/b+1;   return a/b;}
// -------------------------------------------------- Do Not Disturb --------------------------------------------------//

ll helper(ll mask, ll num, vll &freq, vll &primes, vvll &dp)
{
   if(mask == 0)  return 1;
   if(num == 31)  return 0;
   if(dp[mask][num] != -1) return dp[mask][num];

   ll ans = helper(mask, num+1, freq, primes, dp);

   ll check = 0, flag = true;
   f(j, 0, 10)
   {
      if((num%(primes[j]*primes[j])) == 0) flag = false;
      if((num%primes[j]) == 0)  check += (1 << j);
   }
   if(flag && (check & mask) == check)
   {
      ans += (freq[num] * helper(mask - check, num+1, freq, primes, dp))%mod;
      ans %= mod;
   }

   return dp[mask][num] = ans;
}

signed main()
{
   fast;

   in(n);
   vll freq(31, 0), primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
   vvll dp((1 << 10), vll(31, -1));
   f(i, 0, n)
   {
      in(u);
      ++freq[u];
   }

   ll ans = 0;

   f(i, 1, 1 << 10)
   {
      ans += helper(i, 2, freq, primes, dp);
      ans %= mod;
   }

   ans *= powm(2, freq[1]);
   ans %= mod;

   c1(ans);

   return 0;
}
