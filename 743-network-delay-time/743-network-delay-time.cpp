class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) 
    {
        // just created a dis vector that will contain the distance for reaching nodes
        // and make dik[k] initially 0 because we will start dearching from k 
        vector<int>dis(n+1,INT_MAX);
        dis[k]=0;
        
        // we are using here bellman ford algorithm
        // we will update our dis vector upto (n-1) times according to bellman's ford algo
        for(int i=1;i<n;i++)
        {
            // just checking for all the nodes that are available in our graph
            for(int j=0;j<times.size();j++)
            {
                // extracting the information form the current value
                int u=times[j][0];     // source
                int v=times[j][1];     // destination
                int w=times[j][2];     // weight
                 
                // current source is not finite value then we can not pick that path 
                
                // so just check current source is finite or not
                // and we are having better path for reaching V from U by using W
                if(dis[u]!=INT_MAX && dis[u]+w<dis[v])
                {
                    // if we are having better path available then just update our dis
                    dis[v]=w+dis[u];
                }
            }
        }
		 
        // take out the best value to reach n from k
        int ans=0;
        for(int i=1;i<=n;i++)
        {
            // If any node is not reachable from k
            if(dis[i]==INT_MAX) 
                return -1;  
            
            // else take best
            ans=max(ans,dis[i]);
        }
        return ans;
        
    }
};