class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int n = edges.size() + 1;
        vector<int> adj[n+1];
        for(auto it:edges)
        {
            int u = it[0];
            int v = it[1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
         for(int i=0; i<n+1; i++)
        {
            if( adj[i].size() == n-1 ){
                return i;
            }

        }
        return -1;
    }
};