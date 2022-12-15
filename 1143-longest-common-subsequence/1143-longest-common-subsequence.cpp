class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
       int n = text1.length();
       int m = text2.length(); 
        if(n==0||m==0){
            return 0;
        }
       vector<vector<int>> dp(n, vector<int>(m, -1));
        int ans = solve(text1,text2,n-1,m-1,dp);
        return ans;
    }
    int solve(string &text1, string &text2,int n,int m,vector<vector<int>> &dp){
        if(n<0||m<0){
            return 0;
        }
        if(dp[n][m]!=-1){
             return dp[n][m]; 
        }
        if(text1[n]==text2[m]){
          dp[n][m] = solve(text1,text2,n-1,m-1,dp) + 1 ;
        }else{
          dp[n][m] = max(solve(text1,text2,n-1,m,dp),solve(text1,text2,n,m-1,dp));
        }
        
        return dp[n][m];

    }
};