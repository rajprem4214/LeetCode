class Solution {
public:
    void dfs(int node, vector<int>& dist, vector<int>& edges, vector<bool>& vis) {
        vis[node] = 1;

        int it = edges[node];

        if(it != -1 && !vis[it]) {
            vis[it] = true;
            dist[it] = 1 + dist[node];
            dfs(it, dist, edges, vis);
        }
    }

    
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size();

        vector<bool> vis1(n, false);
        vector<bool> vis2(n, false);

        vector<int> dist1(n, INT_MAX);
        vector<int> dist2(n, INT_MAX);

        dist1[node1] = 0;
        dist2[node2] = 0;

        dfs(node1, dist1, edges, vis1);
        dfs(node2, dist2, edges, vis2);

        int minNode = -1;
        int minDistTillNow = INT_MAX;

        for(int i=0; i<n; i++) {
            int maxD = max(dist1[i], dist2[i]);

            if(minDistTillNow > maxD) {
                minDistTillNow = maxD;
                minNode = i;
            }
        }

        return minNode;
    }
};