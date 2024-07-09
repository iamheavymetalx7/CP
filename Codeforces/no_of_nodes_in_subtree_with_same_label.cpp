typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;

#define debug(x) cout << #x <<" "; _print(x); cout << endl;

void _print(ll t) {cout << t;}
void _print(int t) {cout << t;}
void _print(string t) {cout << t;}
void _print(char t) {cout << t;}
void _print(lld t) {cout << t;}
void _print(double t) {cout << t;}
void _print(ull t) {cout << t;}

template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cout << "{"; _print(p.ff); cout << ","; _print(p.ss); cout << "}";}
template <class T> void _print(vector <T> v) {cout << "[ "; for (T i : v) {_print(i); cout << " ";} cout << "]";}
template <class T> void _print(set <T> v) {cout << "[ "; for (T i : v) {_print(i); cout << " ";} cout << "]";}
template <class T> void _print(multiset <T> v) {cout << "[ "; for (T i : v) {_print(i); cout << " ";} cout << "]";}
template <class T, class V> void _print(map <T, V> v) {cout << "[ "; for (auto i : v) {_print(i); cout << " ";} cout << "]";}

class Solution {
public:
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        vector<vector<int>> adjList(n);
        for(int i=0;i<edges.size();i++){
            int x = edges[i][0], y= edges[i][1];
            adjList[x].push_back(y);
            adjList[y].push_back(x);
        }
        
        vector<vector<int>> ans(n, vector<int>(26,0));
        // debug(adjList);
        
        function<void(int,int)> dfs = [&](int node,int par){
            int ch = labels[node] - 'a';
            ans[node][ch]=1;
            for(auto child: adjList[node]){
                if (child==par) continue;
                dfs(child, node);
                
                for(int i=0;i<26;i++){
                    ans[node][i] += ans[child][i];
                }
                
            }
            
        };
        
        
        dfs(0,-1);
        // debug(ans);
        
        vector<int> fin(n,0);
        for(int i=0;i<n;i++){
            int ch = labels[i]-'a';
            fin[i] = ans[i][ch];
        }
        return fin;
        
        
    }
};