class Solution {
public:
    int solve(vector<int>&cost,int n,vector<int>&dp){
        if(n<=1)
         return 0;
        
        if(dp[n]!=-1)
            return dp[n];
        
      int  left = solve(cost,n-1,dp)+ cost[n-1];
      int  right = solve(cost,n-2,dp)+ cost[n-2];
        
    return dp[n]=min(left,right);
    }
    
int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
       vector<int>dp(n+1,-1);
    
        return  solve(cost,n,dp);
    }
};