class Solution {
public:

    // this question is combination of:
    // number of enclaves or surrounded regions &
    // number of province

    void dfs(int row, int col, vector<vector<int>> &vis, vector<vector<int>> &grid, 
        int drow[], int dcol[]) {
            int n = grid.size();
            int m = grid[0].size();

            vis[row][col] = 1;

            for(int i = 0 ; i < 4 ; i++) {
                int nrow = row + drow[i];
                int ncol = col + dcol[i];
                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && grid[nrow][ncol] == 0
                    && !vis[nrow][ncol]) {
                        dfs(nrow, ncol, vis, grid, drow, dcol);
                    }
            }
    }

    int closedIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        // visited grid
        vector<vector<int>> vis(n, vector<int>(m, 0));
        
        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};
        
        // mark all 0 touching with boundary
        // bcs they cannot be part of closed islands
        for(int j = 0 ; j < m ; j++) {
            if(grid[0][j] == 0 && !vis[0][j]) {
                dfs(0, j, vis, grid, drow, dcol);
            }

            if(grid[n-1][j] == 0 && !vis[n-1][j]) {
                dfs(n-1, j, vis, grid, drow, dcol);
            }
        }

        for(int i = 0 ; i < n ; i++) {
            if(grid[i][0] == 0 && !vis[i][0]) {
                dfs(i, 0, vis, grid, drow, dcol);
            }
            
            if(grid[i][m-1] == 0 && !vis[i][m-1]) {
                dfs(i, m-1, vis, grid, drow, dcol);
            }
        }

        // counting closed islands
        // going to one 0 and marking all 0's connected to it
        // this is going to one island
        int cnt = 0;
        for(int i = 0 ; i < n ; i++) {
            for(int j = 0 ; j < m ; j++) {
                if(grid[i][j] == 0 && !vis[i][j]) {
                    cnt++;
                    dfs(i, j, vis, grid, drow, dcol);
                }
            }
        }

        return cnt;
    }
};