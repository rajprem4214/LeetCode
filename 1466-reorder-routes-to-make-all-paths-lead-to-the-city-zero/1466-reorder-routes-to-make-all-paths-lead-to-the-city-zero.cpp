class Solution {
public:
    int ans=0;
    void dfs(int x,vector<int> &vis,vector<pair<int,int>> adj[])
    {
        vis[x]=1;
        for(auto i:adj[x])
        {
            if(!vis[i.first])
            {
                ans+=i.second;
                dfs(i.first,vis,adj);
            }
        }
    }
    int minReorder(int n, vector<vector<int>>& c) {
        vector<pair<int,int>> adj[n];
        vector<int> vis(n,0);
        for(auto i:c)
        {
            adj[i[0]].push_back({i[1],1});
            adj[i[1]].push_back({i[0],0});
        }
        ans=0;
        dfs(0,vis,adj);
        return ans;
    }
};