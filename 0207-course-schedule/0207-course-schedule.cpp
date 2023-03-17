class Solution {
public:
    
    bool hasCycle = false;
    
    void dfs(vector<vector<int>> &graph, int start, vector<bool> &vis, vector<bool> &path)
    {
        if (path[start]) {
            hasCycle = true;
            return;
        }
        if (vis[start] || hasCycle)
            return;
        vis[start] = true;
        path[start] = true;
        for (int post: graph[start]) {
            dfs(graph, post, vis, path);
        }
        path[start] = false;
    }
    
    
    
    bool canFinish(int nc, vector<vector<int>>& pq) {
        vector<vector<int>> graph(nc, vector<int> {});
        for(vector<int> pre: pq)
            graph[pre[1]].emplace_back(pre[0]);
        
        vector<bool> vis(nc, false);
        vector<bool> path(nc, false);
        
        for(int i=0;i<nc;i++)
        {
            dfs(graph, i, vis, path);
        }
        return !hasCycle;
    }
};