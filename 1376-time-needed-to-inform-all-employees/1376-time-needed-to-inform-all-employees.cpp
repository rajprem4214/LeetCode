class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<vector<int>> children(n);
        int ans=INT_MIN;
        for(int i=0; i<n; i++) {
            if(manager[i]!=-1) {
                children[manager[i]].push_back(i);
            }
        }
        queue<pair<int,int>> q;
        q.push({headID,0});
        while(!q.empty()) {
            pair<int,int> p = q.front();
            q.pop();
            ans = max(ans,p.second);
            for(int i=0; i<children[p.first].size(); i++) {
                q.push({children[p.first][i],p.second+informTime[p.first]});
            }
        }
        return ans;
    }
};