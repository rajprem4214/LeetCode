class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        vector<vector<int>> g(n);
        for(auto &i:connections) {
            g[i[0]].emplace_back(i[1]);
            g[i[1]].emplace_back(i[0]);
        }
        vector<bool> vis(n);
        int temp = 0;
        for(int i = 0;i<n;i++) {
            if(vis[i]) continue;
            temp++;
            queue<int> q;
            q.push(i);
            vis[i] = true;
            while(!q.empty()) {
                auto t = q.front();q.pop();
                for(auto &j:g[t]) {

                    if(!vis[j]) {
                        q.push(j);
                        vis[j] = true;
                    }
                }
            }
        }
        int m  = connections.size();
        
        if(m>=n-1) {
            return (temp-1);
        }
        return -1;
    }
};