class Solution {
public:
    
    int dp[101][201];
    int helper(int n,int m,vector<int>& piles){

        if(n>=piles.size()) return 0;
        if(dp[n][m]!=-1) return dp[n][m];
        int total=0;
        int res=INT_MIN;
        for(int i=0 ; i<2*m ; i++){

            if(n+i<piles.size()) total+=piles[n+i];
            res=max(res , total-helper(n+i+1 , max(m,i+1),piles));

        }
        return dp[n][m]=res;
    }
    int stoneGameII(vector<int>& piles) {

        memset(dp,-1,sizeof dp);
        int sum=0;
        for(auto x:piles) sum+=x;
        int diff=helper(0,1,piles);
        return(sum+diff)/2;
        
    }
};