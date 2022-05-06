// { Driver Code Starts
#include <bits/stdc++.h>
 
using namespace std;
 

 // } Driver Code Ends
class Solution{
public:
   void dfs(int v,vector<int>& vis,vector<int> adj[]){
        vis[v] = true;
        for(auto& u:adj[v]){
            if(!vis[u]){
                dfs(u,vis,adj);
            }
        }
    }
    int captainAmerica(int N, int M, vector<vector<int>> &V){
        vector<int> adj[N+1],vis(N+1);
        for(int i=0;i<M;i++){
            int u = V[i][0],v = V[i][1];
            adj[v].push_back(u);
        }
        
        int mother = -1;
        
        for(int i=1;i<=N;i++){
            if(!vis[i]){
                mother = i;
                dfs(i,vis,adj);
            }
        }
        
        fill(vis.begin(),vis.end(),0);
        dfs(mother,vis,adj);
        
        for(int i=1;i<=N;i++){
            if(!vis[i]){
                return 0;
            }
        }
        
        for(int i=1;i<=N;i++){
            adj[i].clear();
        }
        for(int i=0;i<M;i++){
            int u = V[i][0],v = V[i][1];
            adj[u].push_back(v);
        }
        
        queue<int> q;
        q.push(mother);
        
        fill(vis.begin(),vis.end(),0);
        
        vis[mother] = true;
        
        int ans = 0;
        while(!q.empty()){
            int v = q.front();
            q.pop();
            
            ans++;
            for(auto& u:adj[v]){
                if(!vis[u]){
                    q.push(u);
                    vis[u] = true;
                }
            }
        }
        
        return ans;
    } 
};

// { Driver Code Starts.
 

int main() {
    int t;cin >> t;
    while(t--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> v(m+1);
        for(int i=0;i<m;i++){
            int a, b;cin >> a >> b;
            v[i].push_back(a);
            v[i].push_back(b);
        }
        
        Solution obj;
        cout << obj.captainAmerica(n, m, v) << endl;
    }
 
}  // } Driver Code Ends