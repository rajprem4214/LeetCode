class Solution {
public:
    int dfs(int row, int col, vector<vector<int>>& grid,vector<vector<int>> &dp, int dr[]){
        int n=grid.size();
        int m=grid[0].size();
        if(dp[row][col]!=-1) return dp[row][col];
        int maxi=0;
        for(int i=0;i<3;i++){
            int nr=row+dr[i];
            int nc=col+1;
            if(nr>=0 && nr<n && nc>=0 && nc<m && grid[nr][nc]>grid[row][col] ){
                maxi=max(maxi, 1+dfs(nr, nc,grid,dp, dr));
            }
            
        }
        return dp[row][col]=maxi;
    }
    int maxMoves(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int maxi=0;
        int dr[]={-1,0,+1};
        vector<vector<int>> dp(n, vector<int>(m,-1));
        for(int i=0;i<n;i++){
            maxi=max(maxi, dfs(i,0, grid,dp, dr));
        }
        return maxi;
    }
};