class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
         queue<int> q;
        int dir[4][2]={{-1,0},{0,1},{0,-1},{1,0}};
        q.push(entrance[0]*101+entrance[1]);
        int steps=0;
        int m=maze.size(),n=maze[0].size();
        while(!q.empty())
        {
            int size=q.size();
            for(int i=0;i<size;i++)
            {
                int row=q.front()/101,column=q.front()%101;
                q.pop();
                if(row==entrance[0]&&column==entrance[1])
                {

                }else
                if(row==0||row==m-1||column==0||column==n-1)
                {
                    return steps;
                }
                for(int j=0;j<4;j++)
                {
                    int x=row+dir[j][0],y=column+dir[j][1];
                    if(x>=0&&y>=0&&x<m&&y<n&&maze[x][y]=='.')
                    {
                        q.push(x*101+y);
                        maze[x][y]='+';
                    }
                }
            }
            steps++;
            

        }
        return -1;
    }
};