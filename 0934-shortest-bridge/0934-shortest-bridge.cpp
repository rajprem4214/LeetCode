class Solution {
public:
    int shortestBridge(vector<vector<int>>& grid) {
        vector<vector<int>> tempGrid=grid;
        int i=0, j=0, n=grid.size();
        for(i=0;i<n;i++)
        {
            int f=0;
            for(j=0;j<n;j++){
                if(tempGrid[i][j]==1){
                    f=1;
                    break;
                }
            }
            if(f)break;
        }
        queue<pair<int,int>> q,qNew;
        q.push({i,j});
        qNew.push({i,j});
        tempGrid[i][j]=-1;
        int nRow[4]={0,-1,0,1};
        int nCol[4]={1,0,-1,0};
        while(!q.empty())
        {
            int xCor=q.front().first;
            int yCor=q.front().second;
            q.pop();
            for(int k=0;k<4;k++)
            {
                int a=xCor+nRow[k];
                int b=yCor+nCol[k];
                if(a<0 || b<0 || a>=n || b>=n)continue;
                if(tempGrid[a][b]==1){
                    tempGrid[a][b]=-1;
                    q.push({a,b});
                    qNew.push({a,b});
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(tempGrid[i][j]==1)tempGrid[i][j]=-2;
            }
        }
        int count=1,f=0;
        while(!qNew.empty()){
            int sz=qNew.size();
            while(sz--){
                int xCor=qNew.front().first;
                int yCor=qNew.front().second;
                qNew.pop();
                for(int k=0;k<4;k++)
                {
                    int a=xCor+nRow[k];
                    int b=yCor+nCol[k];
                    if(a<0 || b<0 || a>=n || b>=n)continue;
                    if(tempGrid[a][b]==0){
                        tempGrid[a][b]=count;
                        qNew.push({a,b});
                    }
                    else if(tempGrid[a][b]==-2){
                        f=1;
                        break;
                    }
                }
                if(f)break;
            }
            if(f)break;
            count++;
        }
        return count-1;
    }
};