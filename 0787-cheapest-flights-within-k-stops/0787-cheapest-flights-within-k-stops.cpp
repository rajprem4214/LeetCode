class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int, int>> adj[n];
        for(auto it : flights){
            adj[it[0]].push_back({it[1], it[2]});
        }

        queue<pair<int, pair<int, int>>> q; // SC -> O(N + E)
        q.push({0, {src, 0}}); // {stops, {node, distance}}
        vector<int> dist(n, 1e9);
        dist[src] = 0;
        // TC -> O(E)
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            int stops =  it.first;
            int node = it.second.first;
            int cost = it.second.second;

            if(stops > k) continue;

            for(auto iter : adj[node]){
                int adjNode = iter.first;
                int edgeWeight = iter.second;

                if(cost + edgeWeight < dist[adjNode] && stops <= k){
                    dist[adjNode] = cost + edgeWeight;
                    q.push({stops+1, {adjNode, dist[adjNode]}});
                }
            }
        }
        if(dist[dst] == 1e9) return -1;
        else return dist[dst];
    }
};