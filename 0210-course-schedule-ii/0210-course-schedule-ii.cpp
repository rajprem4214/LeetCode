// class Solution {
// public:
    
//     vector<int> findOrder(int nc, vector<vector<int>>& pq) {
//       vector<vector<int>> adj(nc, vector<int>{});
//         for(vector<int> pre: pq)
//             adj[pre[1]].push_back(pre[0]);
    
//         vector<bool> vis(nc, false);
//         stack<int> st;
//         for(int i=0;i<nc;i++)
//         {
//             if(!vis[i])
//             {
//                 dfs(i, vis, st, adj);
//             }
//         }
//         vector<int> ans;
//         while(!st.empty())
//         {
//             ans.push_back(st.top());
//             st.pop();
//         }
//         return ans;
//     }
//     void dfs(int node, vector<bool> &vis, stack<int> &st,  vector<vector<int>> &adj)
//     {
//         vis[node] = 1;
//         for(auto it: adj[node])
//         {
//             if(!vis[it])
//                 dfs(it, vis, st,adj);
//         }
//         st.push(node);
//     }
// };
class Solution {
private:
    bool dfs(int node, vector<int> adj[], vector<int>& vis, vector <int>& tasks) {
        vis[node] = 2;
        for (auto it: adj[node]) {
            if (vis[it] == 0) {
                if (dfs(it, adj, vis, tasks) == true)
                    return true;
            } else if (vis[it] == 2) {
                return true;
            }
        }
        tasks.push_back(node);
        vis[node] = 1;
        return false;  
    }
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int n = prerequisites.size();
        vector <int> vis(numCourses, 0);
        vector <int> adj[numCourses];
        for (int i = 0; i < n; i++) 
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        vector <int> tasks;    
        for (int i = 0; i < numCourses; i++) {
            if (vis[i] == 0) {
                if (dfs(i, adj, vis, tasks) == true)
                    return {};
            }
        }
        reverse(tasks.begin(), tasks.end());
        return tasks;
    }
};