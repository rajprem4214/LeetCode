class Solution {
public:
   void dfs(int i, vector<int>&visited, vector<int> graph[])
    {
        visited[i] = 1;
        for(auto j:graph[i])
            if(!visited[j])
                dfs(j,visited,graph);
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size(), m=isConnected[0].size(), components=0;
        vector<int> graph[n], visited(n,0);
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                if(isConnected[i][j])
                {
                    graph[i].push_back(j);
                    graph[j].push_back(i);
                }
        for(int i=0;i<n;i++)
            if(!visited[i])
            {
                components++;
                dfs(i,visited,graph);
            }
        return components;
    }
};