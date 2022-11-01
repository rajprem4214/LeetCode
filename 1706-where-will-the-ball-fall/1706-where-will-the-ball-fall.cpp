class Solution {
public:
    bool isValid(int rowsize,int colsize,int currow,int currcolo){
        if(currow<0 || currcolo<0 || currow>=rowsize || currcolo>=colsize){
            return false;
        }
        return true;
    }
    int dfs(vector<vector<int>>& grid,int r,int c,int row,int col){
        if(r==row){
            return c;   //we returned the coloum as demanded in the question 
        }
        
        if(isValid(row,col,r,c)){      //isValid checks for if the r c are valid in ranges of grid dimensions
            if(grid[r][c]==1){
                if(isValid(row,col,r,c+1) && grid[r][c+1]==1){      //this if condition confirm a passage with
                    return dfs(grid,r+1,c+1,row,col);               //its right adjacent coloumn and making the
                }                                                   //call for the lower right diagonal element
            }
            else{
                if(isValid(row,col,r,c-1) && grid[r][c-1]==-1){     //this if condition confirm a passage with
                    return dfs(grid,r+1,c-1,row,col);               //its left adjacent coloumn and making the
                }                                                   //call for the lower left diagonal element
            }
        }
        return -1;
    }
    vector<int> findBall(vector<vector<int>>& grid) {
        int row=grid.size();
        int col=grid[0].size();
        vector<int> ans(col);
        for(int c=0;c<col;c++){
            ans[c]=dfs(grid,0,c,row,col);
        }
        return ans;
    }
};