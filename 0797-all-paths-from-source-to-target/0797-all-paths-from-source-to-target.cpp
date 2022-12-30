class Solution {
public:
    
    void dfs(int node, int target, vector<int> temp, vector<vector<int>>& ans, vector<vector<int>> &graph, vector<int> &vis){
        if(node == target){
            temp.push_back(node);
            ans.push_back(temp);
            return;
        }
        
        temp.push_back(node);
        vis[node] = 1;
        
        for(auto nbr:graph[node]){
            if(!vis[nbr]){
                vis[node] = 1;
                dfs(nbr, target, temp, ans, graph, vis);
                vis[node] = 0;
            }
        }
    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<int> temp; 
        vector<int> vis(graph.size(), 0); 
        
        vector<vector<int>> ans;
        dfs(0,graph.size()-1, temp, ans, graph, vis);
        return ans;
    }
};