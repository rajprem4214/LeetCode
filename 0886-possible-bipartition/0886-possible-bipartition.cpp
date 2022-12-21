class Solution {
public:
    void dfs(int curr, vector<int> adjList[], vector<char> &group, bool &ans) {
        if(!ans) return;
        for(int next: adjList[curr]) {
            if(group[next] == 'u') {
                group[next] = 1 - group[curr];
                dfs(next, adjList, group, ans);
            } else if(group[curr] == group[next]) {
                ans = false;
                return;
            }
        }
    }
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        bool ans = true;
        vector<char> group(n + 1, 'u'); 
        vector<int> adjList[n + 1];
        for(vector<int> dislike: dislikes) {
            adjList[dislike[0]].push_back(dislike[1]);
            adjList[dislike[1]].push_back(dislike[0]);
        }
        for(int i = 1; i <= n; i++) {
            if(group[i] == 'u') {
                group[i] = 0;
                dfs(i, adjList, group, ans);
            }
        }
        return ans;
    }
};