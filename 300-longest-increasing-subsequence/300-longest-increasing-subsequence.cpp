class Solution {
public:
    // Memoisation Solution
    int f(vector<int>& nums,int ind,int prev,int n,vector<vector<int>> &dp)
    {
      // Base Case
      if(ind == n)
            return 0;
      // DP condition
        if(dp[ind][prev+1] != -1)
            return dp[ind][prev+1];
        
      // Not take 
      int  len = 0+f(nums,ind+1,prev,n,dp);
      // Take if condition met and update previous
      if(prev == -1 || nums[ind]>nums[prev])
        len = max(len, 1+f(nums,ind+1,ind,n,dp));
        
        return dp[ind][prev+1] = len;
    }
    
    int lengthOfLIS(vector<int>& nums) {
       int n = nums.size();
        vector<vector<int>> dp(n,vector<int>(n+1,-1));
       return f(nums,0,-1,n,dp);
    }
};