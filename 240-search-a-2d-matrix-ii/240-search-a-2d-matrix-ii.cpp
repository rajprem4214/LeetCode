class Solution{
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m= matrix.size() , n= matrix[0].size();  // m and n denotes the no. of rows and columns respectively
        int sr=0, sc=n-1;       //taking last element for reference
        while (sr>=0 && sr<m && sc>=0 && sc<n){
            if (matrix[sr][sc]== target){
                return true;
            }
            else if (matrix[sr][sc]< target){   //target is greater
                sr++;   // move to next row i.e down
            }
            else{   // target is smaller
                sc--;   // move towards smaller elements i.e. left
            }
        }
        return false;
    }
};