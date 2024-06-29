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

struct SegTree {
    
    vector<int> tree;
    int n;
    
    SegTree (int _n) : n(_n) {
        tree.resize(4*n, 0);
    }
    
    void update(int pos, int val, int l = 0, int r = -1, int i = 0) {
        if (r == -1) r += n;
        if (l == r) {
            tree[i] += val;
            return;
        }
        
        int m = (l+r) >> 1;
        if (pos <= m) update(pos, val, l, m, i*2+1);
        else update(pos, val, m+1, r, i*2+2);
        
        tree[i] = tree[i*2+1] + tree[i*2+2];
    }
    
    int query (int x, int y, int l = 0, int r = -1, int i = 0) {
        if (r == -1) r += n;
        if (r < x || l > y) return 0;
        if (l >= x && r <= y) return tree[i];
        
        int m = (l+r) >> 1;
        return (
            query(x, y, l, m, i*2+1) +
            query(x, y, m+1, r, i*2+2)
        );
    }
    void print(){
        for(int i=0;i<tree.size();i++){
            cout<<tree[i]<<" ";
        }
        cout<<endl;
    }
};

void solve()
{
    int n, k;

    cin >> n >> k;
    SegTree tree(n);
    map<int,pair<int,int>> mp;

    int curr=1;

    for (int i = 0; i < k; i++) {

        char tt;
        cin >> tt;
        if (tt == 'P') {
            int x, y;
            cin >> x >> y;

            x--;
            // cout<<x<<" "<<y<<endl;

            tree.update(x,1);
            if (y<n) tree.update(y,-1);
            // tree.print();
            mp[curr] = {x,y};
            curr++;

        }
        else if (tt == 'B') {
            int x;
            cin >> x;
            x--;
            int ans = tree.query(0,x);
            cout << ans << endl;

        }
        else {
            int idx, d;
            cin >> idx >> d;
            pair<int,int> old = mp[idx];
            int fidx = old.ff;
            int sidx = old.ss;
            tree.update(fidx,-1);
            if (sidx<n){
            tree.update(sidx,1);
            }

            fidx+=d;
            sidx+=d;
            tree.update(fidx,1);
            if (sidx<n){
                tree.update(sidx,-1);
            }

        }
    }
}

int32_t main()
{
    fast

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    solve();
    return 0;
}
