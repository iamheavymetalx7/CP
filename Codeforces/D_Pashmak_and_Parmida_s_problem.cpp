#include <bits/stdc++.h>
using namespace std;




struct SegTree {
public:
 
    SegTree (int _n) : n (_n) {
        tree.resize(4*n, 0);
    }
    
    int query (int x, int y) {
        return query (x, y, 0, n-1, 0);
    }
    
    void update (int ind, int val) {
        update (ind, val, 0, n-1, 0);
    }
 
private:
    
    vector<int> tree;
    int n;
    
    int query (int x, int y, int l, int r, int i) {
        if (r < x || l > y) return 0;
        if (l >= x && r <= y) return tree[i];
        
        int m = (l+r) >> 1;
        return (
            query (x, y, l, m, i*2+1) +
            query (x, y, m+1, r, i*2+2)
        );
    }
    
    void update (int ind, int val, int l, int r, int i) {
        if (l == r) {
            tree[i] = val;
            return;
        }
        
        int m = (l+r) >> 1;
        if (m >= ind) update (ind, val, l, m, i*2+1);
        else update (ind, val, m+1, r, i*2+2);
        
        tree[i] = tree[i*2+1] + tree[i*2+2];
    }
};


void solve()
{
  int n;
  cin>>n;
  vector<int> arr(n);
for (int j = 0; j < n; j ++) cin >> arr[j];

    map<int,int> frq;
    vector<int> f1(n),f2(n);
    for(int j=0;j<n;j++){
        frq[arr[j]]++;
        f1[j] = frq[arr[j]];
    }
    frq.clear();
    for(int j=n-1;j>=0;j--){
        frq[arr[j]]++;
        f2[j] = frq[arr[j]];
    }

    vector<pair<int,int>> element_and_ind;
    for(int j=0;j<n;j++){
        element_and_ind.push_back({f1[j],j});
    }
    sort (element_and_ind.begin(), element_and_ind.end());
    map<pair<int,int>, int> position;
	for (int j = 0; j < n; j ++) {
	    position[element_and_ind[j]] = j;
	}

    
    SegTree tree(n);
    long long res =0;

	for (int j = 0; j < n; j ++) {
	    int f1_ind = position[{f1[j], j}];
	    int f2_ind = 
	        upper_bound(element_and_ind.begin(), element_and_ind.end(), make_pair(f2[j], INT_MAX))
	        - element_and_ind.begin();
 
        if (f2_ind < n){
            res += tree.query(f2_ind, n-1);}
            
	    tree.update(f1_ind, 1);        
	}

    cout<<res<<endl;

 

}

signed main()
{
    

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    // int t; cin>>t; while(t--)
    solve();
    return 0;
}