class Solution {
public:
    int dfs(int i, int n, string s, vector<int>&dp)
    {
        if(i == n)
            return 1;
        
        if(dp[i] != -1)
            return dp[i];
        
        int first = s[i+1] == '0' || s[i]=='0' ? 0:dfs(i+1, n,s,dp);
        int second = s[i]!='0' && i+1<n && stoi(s.substr(i, 2)) <= 26 ? dfs(i+2, n,s,dp) : 0;
        
        return dp[i] = first + second;
    }
    
    
    int numDecodings(string s) {
        int n = s.size();
        vector<int> dp(n,-1);
        return dfs(0, n, s, dp);
    }
};