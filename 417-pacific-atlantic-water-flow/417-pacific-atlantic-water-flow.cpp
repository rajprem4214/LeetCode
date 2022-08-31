class Solution {
    
public:
    vector<vector<bool>>pacific,atlantic;
    vector<vector<int>>ans;
    void dfs(vector<vector<int>>&h,vector<vector<bool>>&visited,int i,int j){
        
        int n=h.size(),m=h[0].size();
        // cout<<i<<j<<endl;
        if(visited[i][j])
            return ;
        visited[i][j]=true;
        
        if(pacific[i][j]&&atlantic[i][j]){
            ans.push_back({i,j});
        }
        
        vector<pair<int,int>>p={{1,0},{-1,0},{0,1},{0,-1}};
        for(int k=0;k<p.size();k++){
            int x=i+p[k].first,y=j+p[k].second;
            if(x>=0&&x<n&&y>=0&&y<m&&h[i][j]<=h[x][y]){
                dfs(h,visited,x,y);
            }
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& h) {
        int n=h.size(),m=h[0].size();
        pacific=atlantic=vector<vector<bool>>(n,vector<bool>(m,false));
    
        for(int i=0;i<n;i++){
            dfs(h,pacific,i,0);
            dfs(h,atlantic,i,m-1);
        }
        for(int i=0;i<m;i++){
            dfs(h,pacific,0,i);
            dfs(h,atlantic,n-1,i);
        }
        return ans;
    }
};