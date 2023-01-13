class Solution {
public:
    int n, ans = 1;
    vector<vector<int>> g;
    string alph;

    int dfs(int now) {
        int a = 0, b = 0;
        for(int i = 0; i < g[now].size(); i ++) {
            int x = g[now][i];
            int len = dfs(x);
            ans = max(ans, len);
            if(alph[x] != alph[now]) {
                if(len > a) {
                    b = a;
                    a = len;
                } else {
                    b = max(b, len);
                }
            }
        }
        ans = max(ans, a + b + 1);
        return a + 1;
    }

    int longestPath(vector<int>& parent, string s) {
        n = s.size();
        g = vector<vector<int>>(n, vector<int>(0));
        alph = s;
        for(int i = 1; i < n; i ++) {
            g[parent[i]].push_back(i);
        }
        dfs(0);
        return ans;
    }
};