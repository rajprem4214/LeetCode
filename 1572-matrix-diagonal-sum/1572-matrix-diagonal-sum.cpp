class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int ld=0,rd=0;
        int m=mat.size();
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[i].size();j++){
                if(i==j)
                     ld += mat[i][j];
                else if(i!=j && (i+j+1==m))
                     rd+=mat[i][j];
            }
        }
        return ld+rd;
    }
};