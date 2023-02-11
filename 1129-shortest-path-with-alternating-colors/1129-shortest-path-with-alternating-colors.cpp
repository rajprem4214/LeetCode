class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<int> ans(n, INT_MAX);
        unordered_map<int, vector<int>> adjListR, adjListB;
        for(auto& edge: redEdges){
            adjListR[edge[0]].push_back(edge[1]);
        }
        for(auto& edge: blueEdges){
            adjListB[edge[0]].push_back(edge[1]);
        }
        queue<int> q;
        bool isRed = true;
        q.push(0);
        int dist = 0;
        vector<bool> visitedR(n, false), visitedB(n, false);
        visitedR[0] = true;
        while(!q.empty()){
            int nodeCount = q.size();
            while(nodeCount--){
                int curr = q.front();
                q.pop();
                ans[curr] = min(ans[curr], dist);
                if (isRed){
                    for(int nxt: adjListR[curr]){
                        if (!visitedR[nxt]){
                            visitedR[nxt] = true;
                            q.push(nxt);
                        }
                    }
                }else{
                    for(int nxt: adjListB[curr]){
                        if (!visitedB[nxt]){
                            visitedB[nxt] = true;
                            q.push(nxt);
                        }
                    }
                }
            }
            dist++;
            isRed = !isRed;
        }
        isRed = false;
        q.push(0);
        dist = 0;
        vector<bool> visitedR1(n, false), visitedB1(n, false);
        visitedB1[0] = true;
        while(!q.empty()){
            int nodeCount = q.size();
            while(nodeCount--){
                int curr = q.front();
                q.pop();
                ans[curr] = min(ans[curr], dist);
                if (isRed){
                    for(int nxt: adjListR[curr]){
                        if (!visitedR1[nxt]){
                            visitedR1[nxt] = true;
                            q.push(nxt);
                        }
                    }
                }else{
                    for(int nxt: adjListB[curr]){
                        if (!visitedB1[nxt]){
                            visitedB1[nxt] = true;
                            q.push(nxt);
                        }
                    }
                }
            }
            dist++;
            isRed = !isRed;
        }
        for(int i=0; i<n; i++){
            if (ans[i] == INT_MAX){
                ans[i] = -1;
            }
        }
        return ans;
    }
    
};