class Solution {
public:
    int solve(int i, int j, int d, int m, int n, vector<vector<vector<int>>>& dp) {
        if (i < 0 || i >= m || j < 0 || j >= n) return 1;
        if (d == 0) return 0;
        if (dp[i][j][d] != -1) return dp[i][j][d];

        int ans = (
            (solve(i + 1, j, d - 1, m, n, dp) +
             solve(i - 1, j, d - 1, m, n, dp)) % 1000000007 +
            (solve(i, j + 1, d - 1, m, n, dp) +
             solve(i, j - 1, d - 1, m, n, dp)) % 1000000007
        ) % 1000000007;

        return dp[i][j][d] = ans;
    }

    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(maxMove + 1, -1)));
        return solve(startRow, startColumn, maxMove, m, n, dp);
    }
};