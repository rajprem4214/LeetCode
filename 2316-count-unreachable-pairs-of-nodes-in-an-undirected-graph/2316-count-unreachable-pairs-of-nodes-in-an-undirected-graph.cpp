class Solution {
private:
    int DFS(vector<vector<int>> &adj, vector<bool> &visited, int node){
        visited[node] = true;
        int res = 1;
        for(auto x: adj[node]){
            if(!visited[x]){
                res += DFS(adj, visited, x);
            }
        }
        return res;
    }
public:
    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        vector<bool>visited(n, false);
        for(auto x: edges){
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }
        vector<int> unreachableNode;
        for(int i = 0; i < n; ++i){
            if(!visited[i]){
                int x = DFS(adj, visited, i);
                unreachableNode.push_back(x);
            }
        }
        long long temp = 0;
        long long res = 0;
        for(int i = 0; i < unreachableNode.size(); ++i){
            temp += unreachableNode[i];
            res += (n - temp) * unreachableNode[i];
        }
        return res;
    }
};