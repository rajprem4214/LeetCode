class Solution {
public:
    int find(int node, vector<int>& parent)
    {
        if(node == parent[node])
            return node;
        return parent[node] = find(parent[node], parent);
    }
    void Union(int node0, int node1, vector<int>& parent)
    {
        int par0 = find(node0, parent); 
        int par1 = find(node1, parent);
        if(par0 == par1)
            return;
        parent[par0] = par1;
    }
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edges, vector<vector<int>>& queries) {
        int q = queries.size();
        int sz = edges.size(); 
        vector<int> parent(n, 0); 
        for(int i = 0; i < n; i++) parent[i] = i;
        sort(edges.begin(), edges.end(), [&](vector<int>& edge1, vector<int>& edge2){
            return edge1[2] < edge2[2];
        });
        for(int i = 0; i < q; i++) queries[i].push_back(i);
        sort(queries.begin(), queries.end(), [&](vector<int>& query1,vector<int>& query2) 
        {
            return query1[2] < query2[2];
        });
        vector<bool> ans(q, false);
        int edgeMoment = 0; 
        for(int eachQuery = 0; eachQuery < q; eachQuery++) 
        {
            int currQueryWeight = queries[eachQuery][2]; 
            while(edgeMoment < sz && edges[edgeMoment][2] < currQueryWeight)
            Union(edges[edgeMoment][0], edges[edgeMoment][1], parent), edgeMoment++;
            if(find(queries[eachQuery][0], parent) == 
            find(queries[eachQuery][1], parent))  {

                ans[queries[eachQuery][3]] = true;
            }
        }
        return ans;
    }
};