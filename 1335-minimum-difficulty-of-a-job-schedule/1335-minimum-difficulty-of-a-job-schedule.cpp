class Solution {
    int dp[300][11];
public:
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        memset(dp, -1, sizeof(dp));
        int result = sol(jobDifficulty, 0, jobDifficulty.size()-1, d);
        
        return result == INT_MAX ? -1 : result;
    }
    
    // DP Memoization Approach
    int sol(vector<int>& jobDifficulty, int s, int e, int d)
    {
        int val;

        // Base cases
        if (dp[s][d] != -1)
            return dp[s][d];
        
        if (d == 1)
        {
            val = jobDifficulty[s];
            for (int i = s; i <=e; i++)
            {
                val = max(val, jobDifficulty[i]);
            }
            dp[s][d] = val;
            return val;
        }
        
        // Otherwise
        val = INT_MAX;
        int maxVal = jobDifficulty[s];
        for (int i = s; e-i+1 >= d; i++)
        {
            maxVal = max(maxVal, jobDifficulty[i]);
            val = min(val, maxVal + sol(jobDifficulty, i+1, e, d-1));
        }
        dp[s][d] = val;
        return val;
    }
};