class Solution {
    int dp[2000][2001], n, m;

    int dfs(vector<int>& v1, vector<int>& v2, int ci, int cj) {
        if (ci == n - 1) return 0;
        else if (dp[ci][cj]) return dp[ci][cj] - 1;

        int cur = cj == m ? v1[ci] : v2[cj];
        int ans = v1[ci+1] > cur ? dfs(v1, v2, ci+1, m) : 1e9;

        int idx = upper_bound(v2.begin(), v2.end(), cur) - v2.begin();
        if (idx < m) ans = min(ans, 1 + dfs(v1, v2, ci+1, idx));

        dp[ci][cj] = ans + 1;
        return ans;
    }

public:
    int makeArrayIncreasing(vector<int>& v1, vector<int>& v2) {
        sort(v2.begin(), v2.end());
        n = v1.size(), m = v2.size();
        int ans = min(dfs(v1, v2, 0, m), 1 + dfs(v1, v2, 0, 0));
        return ans == 1e9 ? -1 : ans;
    }
};