// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
int MaxGold(vector<vector<int>>&matrix){
    // Code here
    int row = matrix.size();
   int col = matrix[0].size();
   for(int i=row-1;i>=0;i--)
   {
       for(int j=col-1;j>=0;j--)
       {
           if(matrix[i][j]==-1)
           {
               matrix[i][j]=0;
               continue;
           }
           int left=0,right=0,down=0;
           if(j-1>=0&&i+1<row)
           {
               left = matrix[i+1][j-1];
           }
           if(j+1<col&&i+1<row)
           {
               right = matrix[i+1][j+1];
           }
           if(i+1<row)
           {
               down = matrix[i+1][j];
           }
           matrix[i][j] = matrix[i][j]+max(left,max(down,right));
       }
   }
    
   int ans =0;
   for(int i=0;i<col;i++)
   {
       ans = max(ans,matrix[0][i]);
   }
   return ans;
}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int m, n;
		cin >> m >> n;
		vector<vector<int>>matrix(m, vector<int>(n, 0));
		for(int i = 0; i < m; i++){
			for(int j = 0; j < n; j++)
				cin >> matrix[i][j];
		}
		Solution obj;
		int ans = obj.MaxGold(matrix);
		cout << ans <<'\n';
	}
	return 0;
}  // } Driver Code Ends