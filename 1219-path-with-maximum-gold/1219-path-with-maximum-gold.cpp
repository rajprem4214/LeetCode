class Solution {
public:
    int dfs(int x,int y,int n,int m,vector<vector<int>>& grid)
    {
        if(x<0 || y<0 || x>=n || y>=m || grid[x][y]==0)
            return 0;
        int z = grid[x][y];
        grid[x][y]=0;
        int left = dfs(x-1,y,n,m,grid);
        int right = dfs(x+1,y,n,m,grid);
        int up = dfs(x,y-1,n,m,grid);
        int down = dfs(x,y+1,n,m,grid);
        grid[x][y]=z;
        return z+max(max(left,right),max(up,down));
        
        
    }
    
    
    
    int getMaximumGold(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int ans = INT_MIN;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                
                if(grid[i][j])
                    ans = max(ans,dfs(i,j,n,m,grid));
            }
        }
        return ans==INT_MIN?0:ans;
    }
};