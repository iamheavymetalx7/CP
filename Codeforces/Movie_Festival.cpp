/*

reference  : https://leetcode.com/problems/non-overlapping-intervals/

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

    vector<pair<int,int>> times;
    for(int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        times.push_back({a,b});
    }

    sort(times.begin(),times.end());
    int cnt = 0;
    int end = times[0].second;

    // for (int i = 0; i < n; i++) {
    //     cout << times[i].first << " " << times[i].second << endl;
    // }

    for(int i=1;i<n;i++){
        if (end<=times[i].first){
            end = times[i].second;
        }
        else{
            cnt++;
            end = min(end, times[i].second);
        }
    }
    // cout<<cnt<<endl;
    cout<<n-cnt<<endl;






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