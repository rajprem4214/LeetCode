class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> dp(m+2, vector<int>(n+2, 0));
        vector<pair<int, int>> v;
        for(string x : strs){
            int cnt = count(x.begin(), x.end(), '0');
            v.push_back({cnt, x.size()-cnt});
        }
        for(auto pr : v){
            for(int i=m;i>=0;i--){
                for(int j=n;j>=0;j--){
                    if(i>=pr.first && j>=pr.second){
                        dp[i][j] = max(dp[i][j], 1+dp[i-pr.first][j-pr.second]);
                    }
                }
            }
        }
        return dp[m][n];
    }
};