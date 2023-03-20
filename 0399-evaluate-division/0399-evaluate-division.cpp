class Solution {
public:
    void dfs(unordered_map<string, vector<pair<string, double>>> &mp, unordered_map<string, bool> &vis, string start, string end, double cur, double &ans)
    {
        if(mp.count(start) == 0)
            return;
        
        if(start == end)
        {
            ans = cur;
            return;
        }
        if(ans != -1)
            return;
        
        vis[start] = true;
        for(auto it:mp[start])
        {
            if(vis[it.first] == false)
                dfs(mp, vis, it.first, end, cur*it.second, ans);
        }
        vis[start] = false;
            
    }
    
    
    
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, vector<pair<string, double>>> mp;
        for(int i = 0;i<equations.size();i++)
        {
            mp[equations[i][0]].push_back({equations[i][1], values[i]});
            mp[equations[i][1]].push_back({equations[i][0], 1/values[i]});
        }
        
        unordered_map<string, bool> vis;
        vector<double> ans;
        
        for(int i=0; i<queries.size();i++)
        {
            vis.clear();
            double curAns = -1;
            dfs(mp, vis, queries[i][0], queries[i][1], 1.0, curAns);
            ans.push_back(curAns);
        }
        
        return ans;
        
    }
};