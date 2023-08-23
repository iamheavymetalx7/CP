
#User function Template for python3

class Solution:
    
    #Function to find number of strongly connected components in the graph.
    def kosaraju(self, V, adj):
        # code here
        
        vis=[0]*(V)
        st=[]
        
        def dfs(node,stack):
            vis[node]=1
            
            for nei in adj[node]:
                if not vis[nei]:
                    dfs(nei,stack)
            
            stack.append(node)
        
        for i in range(V):
            if not vis[i]:
                dfs(i,st)
        
        adjT =[[] for _ in range(V)]
        
        for i in range(V):
            vis[i]=0
            for nei in adj[i]:
                adjT[nei].append(i)
        
        
        
        def dfs3(node):
            vis[node]=1
            
            for nei in adjT[node]:
                if not vis[nei]:
                    dfs3(nei)
        
        
        scc=0
        while st:
            node = st.pop()
            if not vis[node]:
                scc+=1
                dfs3(node)
                
        return scc
                