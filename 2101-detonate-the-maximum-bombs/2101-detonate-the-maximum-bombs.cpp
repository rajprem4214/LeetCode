class Solution {
public:

float dist(float x1,float y1,float x2,float y2)
{
    return (float)(sqrt(pow((x2-x1),2)+pow((y2-y1),2)));
}
int bfs(vector<int>Adj[],int node)
{
  queue<int>Q;
  Q.push(node);
  int count=0;
  unordered_map<int,int>Visited;
  while(!Q.empty())
  {
      int node=Q.front();
      Q.pop();
      if(Visited[node]) continue;
      Visited[node]=1;
      count++;
      for(auto adj:Adj[node])
      {
          
         if(Visited[adj]==0) Q.push(adj);
      }

  }
   return count;

}
    int maximumDetonation(vector<vector<int>>& bombs) {
        
       vector<int>Adj[bombs.size()];
        
        for(int i=0;i<bombs.size();i++)
        {
            float x1=bombs[i][0];
            float y1=bombs[i][1];
            float r1=bombs[i][2];
             for(int j=0;j<bombs.size();j++)
             {
                 if(i==j) continue;
                float x2=bombs[j][0];
                float y2=bombs[j][1];
                float distance= dist(x1,y1,x2,y2);
                if(distance<=r1) Adj[i].push_back(j);
             }
        }
     int max_det=0;
    
        for(int i=0;i<bombs.size();i++)
        {
             max_det=max(max_det,bfs(Adj,i));
             cout<<bfs(Adj,i)<<" ";
        }
 

return max_det;

    }
};