class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        // col[i] is the count of 1's in ith column
        vector<int> col(n);
        // First flip all the rows where starting element is not 1 (Because it's the most significant digit)
        for(int i = 0; i < m; i++){
            int cur = grid[i][0];
            if(cur == 0){
                // Flipping the entire row and keeping the count of 1 in every column
                for(int j = 0; j < n; j++){
                    grid[i][j] ^= 1;
                    col[j] += grid[i][j];
                }
            }else{
                // Keeping the count of 1 in every column
                for(int j = 0; j < n; j++){
                    col[j] += grid[i][j];
                }
            }
        }
        // Now for every column if the number of zeros are greater than 1's than flip entire column
        for(int j = 1; j < n; j++){
            if(m-col[j] > col[j]){
                for(int i = 0; i < m; i++){
                    grid[i][j] ^= 1;
                }
            }
        }
        int ans = 0;
        // Simply iterate over the matrix and add all the binary numbers
        for(int i = 0; i < m; i++){
            int cur = 0;
            for(int j = 0; j < n; j++){
                cur*=2;
                cur += grid[i][j];
            }
            ans += cur;
        }
        return ans;
    }
};