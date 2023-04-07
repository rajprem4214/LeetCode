class Solution {
    private:
        bool isValid(int row, int col, int n, int m){
            if(row<0 || col<0 || row>=n || col>=m) return false;
            return true;
        }

        void dfs(int row, int col, int n, int m, vector<vector<int>>& grid){
            grid[row][col] = 0;

            int delRow[] = {1, 0, -1, 0};
            int delCol[] = {0, -1, 0, 1};

            for(int i=0; i<4; i++){
                int newRow = delRow[i] + row;
                int newCol = delCol[i] + col;
                if(isValid(newRow, newCol, n, m) && grid[newRow][newCol] == 1){
                    dfs(newRow, newCol, n, m, grid);
                }
            }
        }
    public:
        int numEnclaves(vector<vector<int>>& grid) {
            int n = grid.size();
            int m = grid[0].size();

            for(int i=0; i<n; i++){
                for(int j=0; j<m; j++){
                    if(i*j == 0 || i == n-1 || j == m-1){
                        if(grid[i][j] == 1){
                            dfs(i, j, n, m, grid);
                        }
                    }
                }
            }

            int count = 0;
            for(int i=0; i<n; i++){
                for(int j=0; j<m; j++){
                    if(grid[i][j] == 1){
                        count++;
                    }
                }
            }

            return count;

        }
};