class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
         vector<vector<vector<int>>> boxes(3, vector<vector<int>>(3, vector<int>(9, 0)));
        vector<vector<int>> columns(9, vector<int>(9, 0));
        
        for(int i=0;i<board.size();i++){
            vector<int> row(9, 0);
            
            for(int j=0;j<board[i].size();j++){
                if(board[i][j] == '.') continue;
                int num = board[i][j]-'1';
                
                if(row[num] != 0) return false;
                row[num] = 1;
                
                if(columns[j][num] != 0) return false;
                columns[j][num] = 1;
                
                if(boxes[i/3][j/3][num] != 0) return false;
                boxes[i/3][j/3][num] = 1;
            }
        }
        
        return true;
    }
};