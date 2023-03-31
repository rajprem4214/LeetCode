class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        // just take transpose of array and reverse each row after that .  - simple observation
        
        int n = matrix.size();
        int m = matrix[0].size();
        
        for(int i=0;i<n-1;i++)
        {
            for(int j=i+1;j<m;j++)
            {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
         for(int i=0;i<n;i++){
            reverse(matrix[i].begin(),matrix[i].end());
        }
        
    }
};