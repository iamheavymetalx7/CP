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

    string bin(int x){
        string val="";
        while(x>0){
            val+=to_string(x%2);
            x/=2;
        }
        reverse(val.begin(),val.end());
        return val;
    }

    //pre-computation



    bool check_bin(int siuu){
        string siiuu = to_string(siuu);
        int szs = siiuu.size();
        for(int i=0;i<szs;i++){
            // cout<<siiuu[i]<<"haha\n";
            if (siiuu[i]=='0' || siiuu[i]=='1'){
                continue;
            }else{
                return false;
            }
        }
        return true;
    }


    void solve()
    {

    vector<int> binnums;

    for(int ii=2;ii<33;ii++){
        string v = bin(ii);
        int vv = stoi(v);
        binnums.push_back(vv);
    }


        int num;
        cin>>num;
        if (check_bin(num)){
            cout<<"YES\n";
            return;
        }

        int sz=binnums.size();

        // cout<<sz<<" :binnums siz3e"<<endl;

        for(int i=0;i<sz;i++){
            if(num%binnums[i]==0){
            while(num%binnums[i]==0){
                num/=binnums[i];
       
            }
         if(num==1){
                    break;
                }
            }
            // cout<<num<<" "<<binnums[/]<<endl;
        }
        if (num==1){
            cout<<"YES \n";
        }
        else{
            cout<<"NO\n";
        }
    

    
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