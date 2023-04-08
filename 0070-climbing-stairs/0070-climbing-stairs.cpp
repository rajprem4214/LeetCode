class Solution {
public:
    // recursive dp
    
    int f(int n, vector<int>&dp)
    {
        if(n==0)
            return 1;
        if(n<0)
            return 0;
        
        if(dp[n] != -1)
            return dp[n];
        
         int one = f(n-1, dp);
        int two = f(n-2, dp);
        
        return dp[n] = one+two;
        
    }
    
    
    int climbStairs(int n) {
        
        vector<int> dp(n+1,-1);
        return f(n, dp);
    }
};