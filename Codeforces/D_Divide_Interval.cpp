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


    vector<int> vec(61,1);

    int maxdivisible2(int n){
        int maxi =0;
        for(int i=60;i>=0;i--){
            // cout<<n%vec[i]<<" "<<vec[i]<<endl;
            if (n%vec[i]==0){
                maxi = max(maxi,i);
                break;
            }
        }
        return maxi;
    }

    pair<int,int> precalc(int maxi,int quo,int r,int i){
        // cout<<"inside precalc"<<endl;
        // if (vec[maxi]*(quo+1)<=r){
        //     cout<<"returning "<<vec[maxi]*(quo+1)<<endl;
        //     cout<<maxi<< " " <<quo<<endl; 
        //     return {maxi,quo};
        // }
        // maxi-=1;
        // quo = i/vec[maxi];
        // cout<<vec[maxi]*(quo+1)<<" "<<maxi<<" "<<quo<< "inside recur\n";
        // precalc(maxi,quo,r,i);

        while (vec[maxi]*(quo+1)>r){
            maxi-=1;
            quo = i/vec[maxi];

        }
        return {maxi,quo};

    }

    void solve()
    {
        int l,r;
        cin>>l>>r;

        vec[0] =1;
        for(int i=1;i<61;i++){
            vec[i]=vec[i-1]*2;
        }

        vector<int> arr;

        int i=l;
        while (i<r){
            int maxi = maxdivisible2(i);
            int quo = i/vec[maxi];
            if (vec[maxi]*(quo+1)<=r){
                arr.push_back(i);
                arr.push_back(vec[maxi]*(quo+1));
                // cout<<i<<" "<<vec[maxi]*(quo+1)<< " .. inside if"<<endl;
                i = vec[maxi]*(quo+1);
                // cout<<"updated i, inside if: "<<i<<endl;
            }
            else{
                // cout<<"now here, greater: "<<vec[maxi]*(quo+1)<<endl;
                
                auto vv= precalc(maxi,quo,r,i);
                maxi = vv.first;
                quo = vv.second;
                // cout<<maxi<<" "<<quo<<" updated ..."<<endl;
                arr.push_back(i);
                i=vec[maxi]*(quo+1);
                // cout<<"updated i: "<<i<<endl;
                arr.push_back(i);
            }
        }
        cout<< arr.size()/2<<endl;

        for(int i=0;i<arr.size();i+=2){
            cout<<arr[i]<<" "<<arr[i+1]<<endl;
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