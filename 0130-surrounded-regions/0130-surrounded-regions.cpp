class Solution {
public:
    void Helper(int m, int n, vector<vector<char>>& board, char mark)
    {
        queue<pair<int,int> > q;
        q.push({m,n});
        board[m][n] = mark;
        int directions[5] = {0,1,0,-1,0};
        while(!q.empty())
        {
            auto curr = q.front();
            q.pop();
            int i = curr.first;
            int j = curr.second;
            
            for(int k=0;k<4;k++)
            {
                int x = i+directions[k];
                int y = j+directions[k+1];
                
                if(x>=0 && x<board.size() && y>=0 && y<board[0].size() && board[x][y]=='O')
                {
                    board[x][y] = mark;
                    q.push({x,y});
                }
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        
        int m = board.size();
        int n = board[0].size();
        if(m==1 || n==1)
            return;
        
         int directions[5] = {0,1,0,-1,0};
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if((i==0 || j==0 || i==(m-1) || j==(n-1)) && board[i][j]=='O') // marking all 'o' which are not surrounded by X  4-directionally and are present  on borders
                    Helper(i,j,board,'#');
            }
        }
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
               if(board[i][j]=='O') // Mark only those O's by X's that are actually surrounded by X 4-directionally
                    Helper(i,j,board,'X');
           }
        }
          for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(board[i][j]=='#') 
                    board[i][j] = 'O';
            }
        }
        
    }
};