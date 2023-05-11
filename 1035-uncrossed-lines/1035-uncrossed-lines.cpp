class Solution {
    // Recursive DP
    int helper(vector<int>& nums1, vector<int>& nums2, int idx1, int idx2, vector<vector<int>>& dp){
        if (idx1 == nums1.size() || idx2 ==  nums2.size()){
            return 0;
        }
        if (dp[idx1][idx2] != -1){
            return dp[idx1][idx2];
        }
        int op1 = helper(nums1, nums2, idx1+1, idx2, dp);
        int i = idx2;
        for(; i<nums2.size(); i++){
            if (nums2[i] == nums1[idx1]){
                break;
            }
        }
        int op2 = 0;
        if (i != nums2.size()){
            op2 = helper(nums1, nums2, idx1+1, i+1, dp)+1;
        }
        dp[idx1][idx2] = max(op1, op2);
        return dp[idx1][idx2];
    }
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        // vector<vector<int>> dp(m, vector<int>(n, -1));
        // return helper(nums1, nums2, 0, 0, dp);
        vector<vector<int>> dp(m, vector<int>(n, 0));
        if (nums1[0] == nums2[0]){
            dp[0][0] = 1;
        }
        for(int i=1; i<m; i++){
            dp[i][0] = dp[i-1][0];
            if (nums1[i] == nums2[0]){
                dp[i][0] = 1;
            }
        }
        for(int i=1; i<n; i++){
            dp[0][i] = dp[0][i-1];
            if (nums1[0] == nums2[i]){
                dp[0][i] = 1;
            }
        }
        for(int i=1; i<m; i++){
            for(int j=1; j<n; j++){
                dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
                if (nums1[i] == nums2[j]){
                    dp[i][j] = max(dp[i][j], dp[i-1][j-1]+1);
                }
            }
        }
        
        return dp[m-1][n-1];
    }
};