class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
          map<int,priority_queue<int, vector<int>, greater<int>>>mp;
        int n=mat.size(),m=mat[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                mp[i-j].push(mat[i][j]);
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                mat[i][j]=mp[i-j].top();
                mp[i-j].pop();
            }
        }
        return mat;
    }
};