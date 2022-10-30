class Solution {
public:
    int solve(vector<vector<int>>&grid,int k)
    {
        vector<vector<int>>v(grid.size(),vector<int>(grid[0].size(),-1));
        queue<vector<int>>q;
        
        q.push({0,0,0,k});
        while(!q.empty())
        {
            auto t = q.front();
            int x = t[0],y = t[1];
            q.pop();
            
            //here is our base case
            
            if(x<0 || y<0 || x>=grid.size() || y>=grid[0].size())
            {
             continue;
            }
            // and here is our return value
            if(x == grid.size()-1 && y == grid[0].size()-1)
            {
                return t[2];
            }
            
            
            if(grid[x][y] == 1)       //if obstacles occured 
            {
                if(t[3]>0)
                {
                    t[3]--;
                }
                else
                {
                    continue;
                }
            }  
			// The cell was previously visited by some path and we were able to remove more                 obstacles from the previous path.
			// Then we don't need to continue on our current path
           if(v[x][y]!=-1 && v[x][y]>=t[3])
                continue;
            v[x][y]=t[3];
            
            // here BFS comes
            q.push({x+1,y,t[2]+1,t[3]});
            q.push({x,y+1,t[2]+1,t[3]});
            q.push({x-1,y,t[2]+1,t[3]});
            q.push({x,y-1,t[2]+1,t[3]});

        }
        return -1;   
    }
    int shortestPath(vector<vector<int>>& grid, int k) {
       return solve(grid,k);
    }
};