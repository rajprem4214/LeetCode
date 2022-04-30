class Solution {
public:
    bool canPutQueen(int r,int c,vector<string>&chess,int n)
    {
         //check for the attack condtion in all 8 direction
        //as we are moving from left to right in the column ,so we will check only 3 direction for left columns
        int r1=r;
        int c1=c;
        // upper diagonal hence moving diagonally
        while(r>=0 & c>=0 )
        {
            if(chess[r][c]=='Q') return false;
            r--;
            c--;
        }
        
        r=r1;
        c=c1;
        // for that row check
        
        while(c>=0)
        {
            if(chess[r][c]=='Q') return false;
            c--;
        }
        //check lower diagonal
        r=r1;c=c1;
        while(r<n && c>=0)
        {
            if(chess[r][c]=='Q') return false;
            r++;
            c--;
        }
        return true;
    }
    
    
    
     void helper(int c,vector<vector<string>>&ans,vector<string>&chess,int n)
     {
         if(c==n) //base condition if all the queens filled correctly
         {
             
             ans.push_back(chess);
             return;
         }
         for(int r=0;r<n;r++)
         {
             //check the attack condition
             if(canPutQueen(r,c,chess,n))
             {  //if doesn't attack put the queen here
                 chess[r][c]='Q';
                 helper(c+1,ans,chess,n);
                 //backtrack then remove the queen from chess 
                 chess[r][c]='.';
                 
                 
             }
         }
         
     }
    
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
        vector<string>chess(n); 
        //fill with dots(.)
        string s(n,'.');
        for(int i=0;i<n;i++)
        {
            chess[i]=s;
        }
        helper(0,ans,chess,n);
        return ans;
    }
};