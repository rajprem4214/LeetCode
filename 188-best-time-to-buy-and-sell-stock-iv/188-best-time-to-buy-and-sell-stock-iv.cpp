class Solution {
public:
    int dp[1002][2][102];
    int helper(int idx,vector<int> &prices,int buy,int k,int trans){
        if(idx >= prices.size() or trans >= k){
            return 0;
        }
        
        if(dp[idx][buy][trans] != -1){
            return dp[idx][buy][trans];
        }
        int a = 0,b=0;
        if(buy){
            a = helper(idx+1,prices,0,k,trans)-prices[idx];    // buy
            b = helper(idx+1,prices,1,k,trans); // not buy
        }
        
        if(!buy){
            a = helper(idx+1,prices,1,k,trans+1)+prices[idx];    // sell
            b = helper(idx+1,prices,0,k,trans);  // not sell
        }
        
        return dp[idx][buy][trans] = max(a,b);
    }
    int maxProfit(int k, vector<int>& prices) {
        memset(dp,-1,sizeof(dp));
        int n = prices.size();
        bool buy = 1;
        int trans = 0;
        return helper(0,prices,buy,k,trans);
    }
};
