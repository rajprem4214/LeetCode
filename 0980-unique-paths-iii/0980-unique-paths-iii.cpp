class Solution {
public:
    int dirX[4] = {1, -1, 0, 0}, dirY[4] = {0, 0, 1, -1};
    int m, n, ans, totalZeroes;

    bool isValid(int &i, int &j){
        return !(i<0 || j<0 || i>=m || j>=n);
    }

    void DFS(vector<vector<int>>& grid, vector<vector<int>>& isVisited, int i, int j, int zeroCovered){
        if( grid[i][j] == 2 ){
            if( zeroCovered == totalZeroes ) ans += 1;
            return;
        }
        isVisited[i][j] = 1;
        for(int k=0;k<4;k++){
            int x = dirX[k] + i, y = dirY[k] + j;
            if( isValid(x, y) && !isVisited[x][y] && grid[x][y] != -1  ){
                DFS(grid, isVisited, x, y, (grid[x][y] == 0)? zeroCovered+1 : zeroCovered);
            }
        }
        isVisited[i][j] = 0;
    }

    int uniquePathsIII(vector<vector<int>>& grid) {
        
        m = grid.size(), n = grid[0].size(), totalZeroes = 0, ans = 0;
        vector<vector<int>> isVisited(m, vector<int>(n, 0));
        int start_i, start_j;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if( grid[i][j] == 0 ) totalZeroes+=1;
                else if( grid[i][j] == 1 ) start_i = i, start_j = j;
            }
        }
        DFS(grid, isVisited, start_i, start_j, 0);
        return ans;
    }       
};