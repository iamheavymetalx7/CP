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
        int n,k;
        cin>>n>>k;
        deque<int> dq(n);
        for (int i = 0; i < n; ++i) {
            cin >> dq[i];
        }
        while (dq.size() > 1 && k) {
            int mn = min(dq.front(), dq.back());
            if (k < 2 * mn) {
                dq.front() -= k / 2 + k % 2;
                dq.back() -= k / 2;
                k = 0;
            } else {
                dq.front() -= mn;
                dq.back() -= mn;
                k -= 2 * mn;
            }
            if (dq.front() == 0) {
                dq.pop_front();
            }
            if (dq.back() == 0) {
                dq.pop_back();
            }
        }
        int ans = n - dq.size();
        cout<<ans+(dq.size() && dq.front()<=k)<<endl;
    
    
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