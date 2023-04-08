class Solution {
public:
    int ans(int n,vector<int> &dp){
        if(n==0) return 1;
        if(dp[n]!=-1) return dp[n];

        int take1=ans(n-1,dp);
        int take2=0;
        if(n>1) take2=ans(n-2,dp);
        return dp[n]=take1+take2;
    }
    int climbStairs(int n) {
        vector<int> dp(n+1,-1);
        return ans(n,dp);
    }
};