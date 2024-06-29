#include <bits/stdc++.h>

// sparse table 

//

//
// /
// /
// /


// /
// /

// /
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

    const int MAX_N = 1e6;
    const int LOG =19;
    int a[MAX_N];
    int m[MAX_N][LOG];
    int logarithm[MAX_N];

    int query(int L, int R){        //O(LOGN)
        int len = R-L+1;
        // int k=0;
        // while((1<<(k+1)) <= len){
        //     k++;
        // }
        int k= logarithm[len];
        return min(m[L][k], m[R-(1<<k)+1][k]);
    }
    
    void solve()

    { 
        // 1. read input
    int n,q;
    cin>>n;


    logarithm[1]=0;
    for(int i=2;i<=n;i++){
        logarithm[i] = logarithm[i/2]+1;
    }
    for(int i=0;i<n;i++){
        cin>>a[i];
        m[i][0]=a[i];
    }

    // 2. preprocessing

    for(int k=1;k<LOG;k++){
        for(int i=0;i+(1<<k)<=n;i++){
            m[i][k] = min(m[i][k-1],m[i+(1<<(k-1))][k-1]);
        }
    }

    // 3. answer queries


    cin>>q;
    for(int i=0;i<q;i++){
        int L,R;
        cin>>L>>R;

        cout<<query(L,R)<<endl;
    }
        

    
    
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


// sparse table 

// sparse table 

// sparse table 

// sparse table 

// sparse table 