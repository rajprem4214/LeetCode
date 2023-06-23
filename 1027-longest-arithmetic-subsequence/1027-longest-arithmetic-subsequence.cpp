class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int n = nums.size();
        if (n <= 2) {
            return n;
        }
        
        vector<unordered_map<int, int>> dp(n);
        int maxLength = 2;
        
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int diff = nums[j] - nums[i];
                
                if (dp[i].count(diff)) {
                    dp[j][diff] = dp[i][diff] + 1;
                } else {
                    dp[j][diff] = 2;
                }
                
                maxLength = max(maxLength, dp[j][diff]);
            }
        }
        
        return maxLength;
    }
};