class Solution {
public:
    int memo [1001][1001] = {0};

    int countPathsDC(int i, int j, vector<vector<int>>& grid){
        // Check if already visited
        if (memo[i][j])
            return memo[i][j];

        int totalCount = 1;
        // Try all the possible paths
        totalCount = (i-1 >= 0 && grid[i][j] < grid[i-1][j])?(totalCount + countPathsDC(i-1,j,grid))%((int) 1e9+7):totalCount;
        totalCount = (i+1 < grid.size() && grid[i][j] < grid[i+1][j])?(totalCount + countPathsDC(i+1,j,grid))%((int) 1e9+7):totalCount;
        totalCount = (j-1 >= 0 && grid[i][j] < grid[i][j-1])?(totalCount + countPathsDC(i,j-1,grid))%((int) 1e9+7):totalCount;
        totalCount = (j+1 < grid[0].size() && grid[i][j] < grid[i][j+1])?(totalCount + countPathsDC(i,j+1,grid))%((int) 1e9+7):totalCount;
        // Assign to memo
        memo[i][j] = totalCount;
        //cout << i << "," << j << ":" << totalCount << std::endl;
        return memo[i][j];
        
    }

    int countPaths(vector<vector<int>>& grid) {
        // Recursive Relation - for any grid position i,j we have dp[i][j] = sum_{adjacent edges}(if adjacent_edge > grid[i][j] then n-1)+1
        // Iterate over all the possible starts Paths
        int totalCount = 0;
        for(int i = 0; i < grid.size(); i++){
            for (int j = 0; j < grid[0].size(); j++){
                totalCount = (totalCount+countPathsDC(i,j, grid))%((int) 1e9+7);
            }
        }
        return totalCount;
    }
};