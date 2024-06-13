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
    string s;
    cin>>s;
    
    string hr,min;
    for(int i=0;i<2;i++){
        hr+=s[i];
    }
    for(int i=3;i<5;i++){
        min+=s[i];
    }
    bool am=true;

    int hour = stoi(hr);

    if (hour>=12){
        am=false;
    }

    if (hour==0){
        hour=12;
    }
    else if(hour>12){
        hour-=12;
    }
    string duration;

    if (am){
        duration="AM";
    }
    else{
        duration = "PM";
    }

    string hrr = to_string(hour);
    if (hrr.size()<2){
        hrr+='0';
        reverse(hrr.begin(), hrr.end());
    }
    cout<<hrr<<":"<<min<<" "<<duration<<"\n";


    
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