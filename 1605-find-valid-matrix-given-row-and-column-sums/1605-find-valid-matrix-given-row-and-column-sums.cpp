class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
         int n = rowSum.size();
        int m = colSum.size();
        vector<vector<int>>v(n,vector<int>(m));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                int minE = min(rowSum[i],colSum[j]);
                v[i][j] = minE;
                rowSum[i] -= minE;
                colSum[j] -= minE;
            }
        }
        return v;
    }
};