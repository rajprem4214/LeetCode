class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        // making a queue to store index i and  j
	
    queue< pair<int ,int> >Q;
	
	// n = size of row 
	// m = size of column
    
    int n =grid.size();
    int m  =grid[0].size();
    
	// making a vector of same rows and columns to store distance from 1 
	
    vector<vector<int>>V( n, vector<int>(m,INT_MAX));
    
	// pushing all the index i and j having value ==1
	// V[i][j] ==  0 as index having value 1 there distance  from 1 in V vector will be  0
    
    for(int i=0 ;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(grid[i][j] == 1)
            {
                Q.push({i , j });
                V[i][j] = 0;
            }
        }
    }
	
	// S == Size of queue
    
    int S ;
	
	// ans   = finalAnswer
	
    int ans  = -1;
    
    while(Q.size() > 0)
    {
        S = Q.size();
        
        for(int i=0;i<S;i++)
        {
            pair<int,int>p = Q.front();
			
			// poping front element and pushing side elements if there distance is greater 
			
            Q.pop();
            
            int f = p.first;
            int s = p.second;
			
			// f and s are index we are checking if they dont go out of index 
			
            if(f+1 < n && V[f+1][s] > V[f][s]+1)
            {
                V[f+1][s] =  V[f][s]+1;
                ans = max(ans , V[f+1][s]);
                Q.push({f+1 , s});
            }
            if(s+1 < m && V[f][s+1] > V[f][s]+1)
            {
                V[f][s+1] =  V[f][s]+1;
                ans = max(ans , V[f][s+1]);
                Q.push({f , s+1});
            }
            if(f-1 >=0 && V[f-1][s] > V[f][s]+1)
            {
                V[f-1][s] =  V[f][s]+1;
                ans = max(ans , V[f-1][s]);
                Q.push({f-1 , s});
            }
            if(s-1 >=0 && V[f][s-1] > V[f][s]+1)
            {
                V[f][s-1] =  V[f][s]+1;
                ans = max(ans , V[f][s-1]);
                Q.push({f , s-1});
            }
        }
       
    }
    return ans;
    }
};