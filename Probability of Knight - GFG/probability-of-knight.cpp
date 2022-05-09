// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
bool isValid(int x,int y,int n)
{
    if(x<0 || y<0 || x>=n || y>=n)
        return false;
   return true;
}
public: double findProb(int n,int x, int y, int steps)
{
    vector<vector<double>>curr(n,vector<double>(n,0.0));
    curr[x][y]=1;
       int dx[8]={-2,-1,1,2, 2, 1,-1,-2};
       int dy[8]={1,  2,2,1,-1,-2,-2,-1};
    for(int move=1;move<=steps;move++)
    {
        vector<vector<double>>next(n,vector<double>(n,0.0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(curr[i][j])
                {
                    for(int k=0;k<8;k++)
                    {
                        int nx = i+dx[k];
                        int ny = j+dy[k];
                        if(isValid(nx,ny,n))
                            next[nx][ny]+= curr[i][j]/8.0;
                    }
                }
            }
        }
        curr = next;
    }
    double ans=0;
    for(auto it:curr)
        for(auto x:it)
            ans+= x;
    return ans;
}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int N, start_x, start_y, steps;
		cin >> N >> start_x >> start_y >> steps;
		Solution ob;
		double ans = ob.findProb(N, start_x, start_y, steps);
		cout << fixed << setprecision(6) << ans <<"\n";
	}  
	return 0;
}  // } Driver Code Ends