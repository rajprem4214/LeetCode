class Solution {
public:
    void dfs(int node, vector<int> &edges, vector<bool> &visited, 
    vector<int>&low, int &maxi){
        if (edges[node]!=-1){
            int v = edges[node];
            if (low[v]==-1){
                low[v] = low[node]+1;
                dfs(v, edges, visited, low, maxi);
            }
            else if (low[v]!=-1 && !visited[v]){
                maxi = max(maxi, low[node]-low[v]+1);
            }
        }
        visited[node] = true;
    }
    int longestCycle(vector<int>& edges) {
        int n = edges.size();
        vector<bool> visited(n, false);
        vector<int> low(n, -1);
        int maxi  =-1;

        for (int i=0; i<n; i++){
            if (!visited[i]){
                dfs(i, edges, visited, low, maxi);
            }
        }

        return maxi;
    }
};