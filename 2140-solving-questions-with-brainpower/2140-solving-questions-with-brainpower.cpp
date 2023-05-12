class Solution {
public:
    
    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        vector<long long> dp(n+1,0);
        
        long long validJumps;
        for(int i=n-1;i>=0;i--)
        {
            long long points = questions[i][0];
            long long jumps = questions[i][1];
            
            if(i + jumps + 1 > n)
                validJumps = 0;
            else
                validJumps = i + jumps + 1;
            
            dp[i] += max(points + dp[validJumps], dp[i+1]);
        }
        
        return dp[0];
        
        
    }
};