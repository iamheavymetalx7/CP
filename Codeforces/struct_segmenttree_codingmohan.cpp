
struct SegTree {
    
    vector<int> tree;
    int n;
    
    SegTree (int _n) : n(_n) {
        tree.resize(4*n, 0);
    }
    
    void update(int pos, int val, int l = 0, int r = -1, int i = 0) {
        if (r == -1) r += n;
        if (l == r) {
            tree[i] = val;
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
};