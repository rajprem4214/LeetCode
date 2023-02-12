class Solution {
public:
long long res;
long long dfs(int src,int par,vector<vector<int>>&graph,int seats){
 
       long long temp=1;

       for(auto child: graph[src]){

           if(child!=par){
              
              temp+=dfs(child,src,graph,seats);
           }
       }
    
    if(src!=0){

        res+=ceil((double)temp/seats);
    }

    return temp;
  
    }

   
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        int n=roads.size();

        vector<vector<int>>graph(n+1);

        for(vector<int>v: roads){
              
              graph[v[0]].push_back(v[1]);
              graph[v[1]].push_back(v[0]);
        }

        // vector<vector<bool>>vis(n,vector<bool>(n,false));

        res=0;
        dfs(0,-1,graph,seats);

        return res;
    }
};