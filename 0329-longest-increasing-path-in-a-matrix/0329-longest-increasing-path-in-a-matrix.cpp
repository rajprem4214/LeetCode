class Solution {
public:
    int vis[200][200];
    int tra(vector<vector<int>>&arr,int i,int j,int x,int y){
        if(i<0||i>=arr.size()||j<0||j>=arr[0].size()){
            return 0;
        }
        if(x!=-1&&y!=-1&&arr[i][j]<=arr[x][y]){
            return 0;
        }
        if(x!=-1&&y!=-1&&arr[i][j]>arr[x][y]&&vis[i][j]!=0){
            return vis[i][j];
        }
        int ct=0;
        ct=max(ct,tra(arr,i-1,j,i,j));
        ct=max(ct,tra(arr,i+1,j,i,j));
        ct=max(ct,tra(arr,i,j-1,i,j));
        ct=max(ct,tra(arr,i,j+1,i,j));
        return vis[i][j]=ct+1;
    }
    int longestIncreasingPath(vector<vector<int>>& arr) {
        int ans=0;
        for(int i=0;i<arr.size();i++){
            for(int j=0;j<arr[0].size();j++){
                if(vis[i][j]==0){
                    tra(arr,i,j,-1,-1);
                }
                ans=max(ans,vis[i][j]);
            }
        }
        return ans;
    }
};