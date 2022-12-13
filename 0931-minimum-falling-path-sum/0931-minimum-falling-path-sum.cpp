class Solution {
public:
    vector<vector<int>>dp;
    int dfs(vector<vector<int>>& matrix , int i , int j){
        if(j >= matrix.size() || i>=matrix.size() || j<0){
            if(i >= matrix.size())return 0;
            return 1e6;
        }
        if(dp[i][j]!=1e9)return dp[i][j];
        return dp[i][j] = matrix[i][j] + min({dfs(matrix , i + 1 , j - 1) , dfs(matrix , i + 1 , j),
        dfs(matrix , i + 1 , j + 1)}); 
    }

    int minFallingPathSum(vector<vector<int>>& matrix) {
       int ans = INT_MAX;
       int n = matrix.size();
        dp.assign(n, vector<int>(n , 1e9));

       for(int i = 0; i < matrix.size(); i++){
           ans = min(dfs(matrix , 0 , i) , ans);
       }
       return ans;
    }
};