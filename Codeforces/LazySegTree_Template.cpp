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


    class ST{
        vector<int> st;
        vector<int> lazy;

    public:
        ST(int n){
            st.resize(4*n+1);
            lazy.resize(4*n+1);
        }

        void build(int ind, int low, int high, int arr[]){
            if (low==high){
                st[ind] = arr[low];
                return;
            }
            int mid = (low+high)>>1;
            build(2*ind+1,low,mid,arr);
            build(2*ind+2,mid+1,high,arr);
            st[ind]=(st[2*ind+1]+st[2*ind+2]);
        }

        void update(int ind, int low, int high, int l, int r, int val)
        {
            if (lazy[ind]!=0){
                st[ind] += (high-low+1)*lazy[ind];
                if (low!=high){
                lazy[2*ind+1]+=lazy[ind];
                lazy[2*ind+2]+=lazy[ind];

                }

                lazy[ind]=0;
            }

            //no overlap l r low high or low high l r
            if (r<low or l>high){
                return;
            }

            //complete overlap l low high r
            if (low>=l && high<=r){
                st[ind]+=(high-low+1)*val;
                if (low!=high){
                    lazy[2*ind+1]+=val;
                    lazy[2*ind+2]+=val;
                }
                return;
            }

            int mid = (low+high)>>1;
            update(2*ind+1,low,mid,l,r,val);
            update(2*ind+2,mid+1,high,l,r,val);
            st[ind]=st[2*ind+1]+st[2*ind+2];
    

        }
        int query(int ind, int low, int high, int l, int r){
            // update if anytinng remains;
            if(lazy[ind]!=0){
                st[ind]+=(high-low+1)*lazy[ind];
                if (low!=high){
                    lazy[2*ind+1]+=lazy[ind];
                    lazy[2*ind+2]+=lazy[ind];
                }
                lazy[ind]=0;
            }



            // no overlap l r low high or low high l r
            if (r<low or l>high){
                return 0;
            }

            // complete overlap;
            //complete overlap l low high r
            if (low>=l && high<=r){
                return st[ind];
            }
            int mid = (low+high)>>1;
            int left = query(2*ind+1, low,mid, l,r);
            int right = query(2*ind+2, mid+1,high, l,r);
            return left+right;


        }
    };
    
    void solve()
    {	int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
            // cout<<arr[i]<<endl;
        }

        ST st1(n);

        st1.build(0,0,n-1,arr);

        int q;
        cin>>q;


        while (q--){
            int type;
            cin>>type;

            if (type==1){
                int l,r;
                cin>>l>>r;
                cout<<st1.query(0,0,n-1,l,r)<<endl;
            
            }
            else{
                int l,r,val;
                cin>>l>>r>>val;
                st1.update(0,0,n-1,l,r,val);

            }
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