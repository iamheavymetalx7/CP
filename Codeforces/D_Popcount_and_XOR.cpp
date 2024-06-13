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
    
    string to_bin( int x){
        string s="";
        
        while(x>0){
            if (x%2){
                s+="1";
            }
            else{
                s+="0";
            }
            x/=2;
        }
        while(s.size()<60){
            s+="0";
        }
        reverse(s.begin(),s.end());
        return s;

    }

    int bin_to_dec(string s){
        int n=s.size();
        reverse(s.begin(),s.end());
        int ans =0;
        for(int i=0;i<n;i++){
            if(s[i]=='1'){
            ans += pow(2,i);}
        }
        return ans;
    }

    void solve()
    {
    unsigned a, b;
    unsigned long C;
    cin >> a >> b >> C;
    unsigned c = __builtin_popcountll(C);

    if((a + b + c) % 2 != 0 || a + b + c > 120 || a > b + c || b > c + a || c > a + b){
        cout << "-1" << endl;
        return;
    }

    // n?? = the number of k such that the k-th digit of X and Y are ??
    unsigned n00{60 - (a + b + c) / 2}, n01{(-a + b + c) / 2}, n10{(a - b + c) / 2}, n11{(a + b - c) / 2};

    unsigned long X{}, Y{};
    for(unsigned B = 60; B--;){ // Scan from the higher digit
        // Lift one bit each
        X *= 2;
        Y *= 2;

        if(1 & (C >> B)){ // If B-th bit of C is 1
            if(n10){ // if (1, 0) is in stock
                ++X; // set the B-th bit of X to 1, and of Y to 0
                --n10; // consume the stock
            }else{ // otherwise
                ++Y; // set that of Y to 1
                --n01; // consume the stock
            }
        }else{ // If B-th bit of C is 0
            if(n00){ // if (0, 0) is in stock
                --n00; // set both of them to 0, and consume the stock
            }else{ // otherwise
                ++X; // set both of them to 1,
                ++Y;
                --n11; // and consume the stock
            }
        }
    }

    cout << X << " " << Y << endl;
    return;
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