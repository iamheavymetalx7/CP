// https://leetcode.com/problems/find-minimum-diameter-after-merging-two-trees/

class Solution {
    
    
    vector<vector<int>> g;
    vector<int> in, out;
    
    void dfs (int u, int par) {
            in[u]=0;
            for(auto v: g[u]){
                if (v==par) continue;
                
                dfs(v,u);
                in[u] =max(in[v]+1,in[u]);
            }
        }
        
    void dfs2 (int u, int par) {
        int mx1(-1),mx2(-1);
        for(auto v: g[u]){
            if(v==par) continue;

            if (in[v]>=mx1) mx2=mx1, mx1=in[v];
            else if(in[v]>mx2) mx2 =in[v];

        }

        for(auto v: g[u]){
            if(v==par)continue;
            int use =mx1;
            if (mx1==in[v]) use=mx2;
            out[v] = max(1+out[u], use+2);
            dfs2(v,u);
        }
    }

    vector<int> maxDepth (vector<vector<int>>& edges) {
        int n = edges.size()+1;
        g.clear(), in.clear(), out.clear();
        g.resize(n), in.resize(n, 0), out.resize(n, 0);
        
        for (auto e : edges) {
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }
        
        dfs (0, -1);
        dfs2 (0, -1);
        
        for (int i = 0; i < n; i ++) 
            out[i] = max (out[i], in[i]);
        
        return out;
    }
        
    
public:
    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        int n1 = edges1.size()+1;
        int n2 = edges2.size()+1;
        
        vector<int> depth1 = maxDepth(edges1);
        vector<int> depth2 = maxDepth(edges2);
        
        int d1,d2,d1min,d2min,ans=0;
        d1 = *max_element(depth1.begin(),depth1.end());
        d2 = *max_element(depth2.begin(),depth2.end());
        
        d1min = *min_element(depth1.begin(),depth1.end());
        d2min = *min_element(depth2.begin(),depth2.end());
        vector<int> vec;
        vec.push_back(d1);
        vec.push_back(d2);
        vec.push_back(d1min+d2min+1);
       ans = *max_element(vec.begin(),vec.end());
           return ans;
        
    }
};