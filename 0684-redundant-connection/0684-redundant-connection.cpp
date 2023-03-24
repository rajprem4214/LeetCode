class Solution {
public:
    bool dfs(vector<vector<int>> &adj,vector<int> &visited,int v,int parent){
        visited[v]=1;
        for(int i=0;i<adj[v].size();i++){
            if(!visited[adj[v][i]]){
                if(dfs(adj,visited,adj[v][i],v)){
                    return true;
                }
            }else if(parent!=adj[v][i]){
                return true;
            }
        }
        return false;
        // visited[v] = 0;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int> res;
        int n=edges.size();
        int minV=INT_MAX;
        vector<vector<int>> adj(n+1);
       
        for(int i=0;i<n;i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
             vector<int> visited(n+1,0);
            if(dfs(adj,visited,edges[i][0],-1)){
                res={edges[i][0],edges[i][1]};
                break;
            }
        }
        return res;
    }
};