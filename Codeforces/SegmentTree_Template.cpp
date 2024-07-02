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

    class SGTree{
    
        vector<int> seg;

    public:
        
        SGTree(int n){
            seg.resize(4*n+1);
        }
        void build(int ind, int low , int high, int arr[]){
            if (low==high){
                seg[ind]= arr[low];
                return;
            }

            int mid = (low+high)>>1;
            build(2*ind+1, low, mid, arr);
            build(2*ind+2, mid+1,high,arr);

            seg[ind]= min(seg[2*ind+1],seg[2*ind+2]);

        }


        int query(int ind, int low, int high,int l, int r){
            // no overlap low high l r or l r low high
            if (l>high || r<low){
                return INT_MAX;
            }

            // complete overlap
            //l low high r
            if (low>=l && high<=r){
                return seg[ind];
            }
            int mid = (low+high)>>1;
            int left = query(2*ind+1,low,mid,l,r);
            int right = query(2*ind+2, mid+1, high,l,r);
            return min(left,right);

        }

        void update(int ind, int low, int high, int i,int val){
            if(low==high){
                seg[ind]=val;
                return;
            }
            int mid = (low+high)>>1;
            if (i<=mid){
                update(2*ind+1,low,mid,i,val);        }
            else{
                update(2*ind+2,mid+1,high,i,val);
            }
            seg[ind]=min(seg[2*ind+1],seg[2*ind+2]);

            
        }
        void show(){
            for(int i=0;i<seg.size();i++){
                cout<<seg[i]<<" ";
            }
            cout<<endl;
        }
        };
        


        void solve()
        {	int n;
            cin>>n;
            int arr[n];
            for(int i=0;i<n;i++){
                cin>>arr[i];
            }
            // int seg[4*n];
            SGTree sg1(n);
            sg1.build(0,0,n-1,arr);
            sg1.show();
            int idx,val;
            cin>>idx>>val;
            sg1.update(0,0,n-1,idx,val);
            sg1.show();
            // int q;
            // cin>>q;

            // while(q--){
            //     // int l,r;
            //     // cin>>l>>r;
            //     // cout<<q<<" "<<query(0,0,n-1,l,r,seg)<<endl;

            //     int type;
            //     cin>>type;
            //     if (type==1){
            //         int l,r;
            //         cin>>l>>r;
            //         cout<<sg1.query(0,0,n-1,l,r)<<endl;
            //     }
            //     else{
            //         int i,val;
            //         cin>>i>>val;
            //         sg1.update(0,0,n-1,i,val);
            //         arr[i]=val;
            //     }
                
            // }


    
     
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