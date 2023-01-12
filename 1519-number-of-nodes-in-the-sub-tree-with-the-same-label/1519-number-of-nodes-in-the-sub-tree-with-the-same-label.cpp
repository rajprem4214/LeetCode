class Solution {
public:
    vector<int> solve(int p, int curr, const vector<vector<int>>& adj, const string &labels, vector<int> &ans) {
        vector<int> x(26, 0);
        x[labels[curr]-'a']++;

        for(int v : adj[curr]) {
            if(p != v) {
                vector<int> temp = solve(curr, v, adj, labels, ans);
                for(int i = 0; i < 26; i++)
                    x[i] += temp[i];
            }
        }

        ans[curr] = x[labels[curr]-'a'];
        return x;
    }

    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        vector<vector<int>> adj(n);
        for(auto k : edges) {
            adj[k[0]].push_back(k[1]);
            adj[k[1]].push_back(k[0]);
        }
        vector<int> ans(n, 0);
        solve(-1, 0, adj, labels, ans);
        return ans;
    }
};