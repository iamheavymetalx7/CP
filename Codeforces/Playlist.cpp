/*

sliding window !!
reference: https://github.com/iamprayush/cses-problemset-solutions/blob/master/solutions/Sorting%20and%20Searching/playlist.cpp

*/
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
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }


    int i = 0, j = 0, max_len = 0, curr_len = 0;
	map<int, int> freq;
	while (j < n)
	{
		if (freq.find(arr[j]) == freq.end() || freq[arr[j]] == 0)
		{
			freq[arr[j]]++;
			curr_len++;
			max_len = max(max_len, curr_len);
			j++;
		}
		else
		{
			curr_len--;
			freq[arr[i]]--;
			i++;
		}
	}
	    cout << max_len;
    
    
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