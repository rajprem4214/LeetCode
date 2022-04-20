class Solution {
public:
int flag = 0;

void dfs(int i,int j,vector<vector<char>>& board, int p, string word, vector<vector<int>>&vis)
{
    if(p == word.size()-1)
    {
        flag = 1;
        return;
    }
    vis[i][j] = 1;
    if(i-1>=0 && i-1<board.size() && j>=0 && j<board[0].size() && word[p+1] == board[i-1][j] && vis[i-1][j] == 0)
    {
        dfs(i-1,j,board,p+1,word,vis);
    }
    if(i+1>=0 && i+1<board.size() && j>=0 && j<board[0].size() && word[p+1] == board[i+1][j] && vis[i+1][j] == 0)
    {
        dfs(i+1,j,board,p+1,word,vis);
    }
    if(i>=0 && i<board.size() && j-1>=0 && j-1<board[0].size() && word[p+1] == board[i][j-1] && vis[i][j-1] == 0)
    {
        dfs(i,j-1,board,p+1,word,vis);
    }
    if(i>=0 && i<board.size() && j+1>=0 && j+1<board[0].size() && word[p+1] == board[i][j+1] && vis[i][j+1] == 0)
    {
        dfs(i,j+1,board,p+1,word,vis);
    }
    vis[i][j] = 0;
}

bool exist(vector<vector<char>>& board, string word) {
    vector<vector<int>>vis;
    vector<int>push(board[0].size(),0);
    for(int i=0;i<board.size();i++)
    {
        vis.push_back(push);
    }
   
    for(int i=0;i<board.size();i++)
    {
        for(int j=0;j<board[0].size();j++)
        {
            if(board[i][j] == word[0])
            {
                dfs(i,j,board,0,word,vis);
            }
        }
    }
    if(flag == 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}
};