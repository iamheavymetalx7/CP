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

    int dp[40];
    int minWt;
    vector<int> cost;
  int recur(int idx){
    if (idx<0){
        return 0;
    }
    if(dp[idx]!=-1){
        return dp[idx];
    }
    int ans=1e18;

	if((minWt & (1LL << idx)) > 0){
        ans = min(ans, cost[idx]+recur(idx-1));
    }
    else{

		ans = min(ans, cost[idx]);
		ans = min(ans, recur(idx-1));
	}

	return dp[idx] = ans;


  }
    
    void solve()

    {

		int n;
		cin>>n;
        cost.resize(n);
		for(int i=0;i<n;i++){
			cin>>cost[i];
		}

		// for(int i=0;i<n;i++){
		// 	cout<<cost[i]<<endl;
		// }
    cin>>minWt;

    for(int i=1;i<n;i++){
        cost[i] =min(2*cost[i-1],cost[i]);
    }
    memset(dp,-1,sizeof(dp));
    int ans = recur(n-1);
    cout<<ans<<endl;
    

    
    
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