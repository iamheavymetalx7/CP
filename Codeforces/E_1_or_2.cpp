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
#define w(x)  \
    int x;    \
    cin >> x; \
    while (x--)
#define fast ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

struct UnionFind
{
    int n, set_size, *parent, *rank;
    UnionFind() {}
    UnionFind(int a)
    {
        n = set_size = a;
        parent = new int[n + 1];
        rank = new int[n + 1];
        for (int i = 1; i <= n; i++)
        {
            parent[i] = i;
            rank[i] = 1;
        }
    }
    int find(int x)
    {
        if (x != parent[x])
            return parent[x] = find(parent[x]);
        return x;
    }
    void merge(int x, int y)
    {
        int xroot = find(x);
        int yroot = find(y);
        if (xroot != yroot)
        {
            if (rank[xroot] >= rank[yroot])
            {
                rank[xroot] += rank[yroot];
                parent[yroot] = xroot;
            }
            else
            {
                rank[yroot] += rank[xroot];
                parent[xroot] = yroot;
            }
            set_size -= 1;
        }
    }
    void reset()
    {
        set_size = n;
        for (int i = 1; i <= n; i++)
        {
            parent[i] = i;
            rank[i] = 1;
        }
    }
    int size() { return set_size; }
    void print()
    {
        for (int i = 1; i <= n; i++)
        {
            cout << i << " -> " << parent[i] << "\n";
        }
    }
};

void solve()
{
    int n, m;
    cin >> n >> m;
    UnionFind uf(n);
    int a, b, c;
    rep(i, 0, m)
    {
        cin >> a >> b >> c;
        uf.merge(a, b);
    }
    cout << uf.size() << "\n";
}

signed main()
{
    fast
    // int t; cin>>t; while(t--)
    solve();
    return 0;
}