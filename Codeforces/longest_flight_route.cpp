#include <bits/stdc++.h>

using namespace std;

#define ll long long int
#define ld long double
#define mod 1000000007
#define inf 1e9
#define endl "\n"
#define pb push_back
#define vi vector<ll>
#define vs vector<string>
#define pii pair<ll,ll>
#define loop(i,a,b) for(int i=a ; i<=b ; i++)

const int N = 1e6;

vector<vector<ll>> Adj(N, vector<ll>());
vector<ll> Par(N, -1);
vector<ll> Deg(N, 0);

void topo(queue<ll> &Q) {
    while (!Q.empty()) {
        int x = Q.front();
        Q.pop();
        for (ll t : Adj[x]) {
            Deg[t]--;
            if (Deg[t] == 0) {
                Par[t] = x;
                if (t != 1) {
                    Q.push(t);
                }
            }
        }
    }
}

int main(int argc, char const *argv[]) {
    ll n, m;
    cin >> n >> m;

    ll a, b;
    for (ll i = 1; i <= n; i++) {
        Deg[i] = 0;
        Par[i] = -1;
    }

    loop(i, 0, m-1) {
        cin >> a >> b;
        Adj[a].pb(b);
        Deg[b]++;
    }

    queue<ll> Q;
    for (ll i = 2; i <= n; i++) {
        if (Deg[i] == 0) {
            Q.push(i);
        }
    }

    topo(Q);

    Q.push(1);
    Par[n] = -1;
    Par[1] = -1;
    topo(Q);

    if (Par[n] == -1) {
        cout << "IMPOSSIBLE";
    } else {
        ll cur = n;
        vector<ll> Ans;
        while (Par[cur] != -1) {
            Ans.push_back(cur);
            cur = Par[cur];
        }
        Ans.push_back(1);
        cout << Ans.size() << endl;
        reverse(Ans.begin(), Ans.end());
        loop(i, 0, Ans.size() - 1) {
            cout << Ans[i] << " ";
        }
    }
    return 0;
}