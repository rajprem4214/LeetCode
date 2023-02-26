class Solution {
public:
    int flag = 0;
    bool dfs(vector<int> adj[], int src, int des, vector<bool> &vis)
    {
        vis[src] = true;
        if(src == des)
            return true;
        for(auto it:adj[src])
        {
            if(!vis[it])
            {
                if(dfs(adj, it, des, vis))
                    return true;
            }
        }
        return false;
        
    }
    bool validPath(int n, vector<vector<int>>& edges, int src, int des) {
        vector<bool>vis(n,0);
        vector<int> adj[n+1];
        for(int i=0;i<edges.size();i++)
        {
           int u = edges[i][0];
            int v =edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
      return  dfs(adj, src, des, vis);
    }
};