// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
    public:
    //Function to find whether a path exists from the source to destination.
    bool is_Possible(vector<vector<int>>& grid) 
    {
        int dx[4]={1,-1,0,0};
   int dy[4]={0,0,1,-1};
       queue<pair<int,int>>q;
       int m=grid.size();
       int n=grid[0].size();
       for(int i=0;i<m;i++){
           for(int j=0;j<n;j++){
               if(grid[i][j]==1){
                 q.push({i,j});
                 break;
               }
           }
       }
       while(!q.empty()){
           auto p=q.front();
           q.pop();
           int a=p.first;
           int b=p.second;
           if(grid[a][b]==2)
              return 1;
              grid[a][b]=0;
             for(int i=0;i<4;i++){
                 int x=a+dx[i];
                 int y=b+dy[i];
             //   cout<<x<<y;
   
                
                 if(x>=0 && y>=0 && x<m && y<n && (grid[x][y]==3||grid[x][y]==2)){
                     if(grid[x][y]==2)
                         return 1;
                   else if(grid[x][y]==3)
                        q.push({x,y});
                 }
                 
             }
       }
   
      
       //code here
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>grid(n, vector<int>(n, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		bool ans = obj.is_Possible(grid);
		cout << ((ans) ? "1\n" : "0\n");
	}
	return 0;
}  // } Driver Code Ends