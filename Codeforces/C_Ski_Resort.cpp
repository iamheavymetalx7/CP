/*
Bhukya Tharun  |,,|
*/

// #include<bits/stdc++.h>

// #define endl "\n"
// #define int long long
// #define debug(x) cout<<#x<<": "<<x<<endl;
// #define google cout<<"Case #" << tc << ": ";

// using namespace std;

void solve(int tc)
{
    int n,k,q;
    cin>>n>>k>>q;
    int a[n];
    for(int i=0; i<n; i++) cin>>a[i];
    int c=0;
    int ans=0;
    for(int i=0;i<n;i++){
        if(a[i]>q){
            if(c>=k) ans+=(c-k+1)*(c-k+2)/2;
            c=0;
        }
        else{
            c++;
        }
    }
    if(c>=k) ans+=(c-k+1)*(c-k+2)/2;
    cout<<ans<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t=1;
    cin>>t;
    for(int tc=1;tc<=t;tc++) solve(tc);
    return 0;
}