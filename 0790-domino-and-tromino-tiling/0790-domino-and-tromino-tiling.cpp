class Solution {
private:
    const int mod = 1e9 + 7;
    int dp[2][1001];

    long rec(int a, bool gap) {
        if(a < 0)
            return 0;
        
        if(a == 0)
            return (gap == 0) ? 1 : 0; // if gap is 0, means grid is completely occupied, else not

        if(dp[gap][a] != -1)
            return dp[gap][a];
        
        if(gap == 0)
            return dp[gap][a] = (rec(a - 1, 0) + rec(a - 2 , 0) + 2 * rec(a - 2, 1)) % mod;
        
        return dp[gap][a] = (rec(a - 1, 1) + rec(a - 1, 0)) % mod;
    }
    
public:
    int numTilings(int a) {
        memset(dp, -1, sizeof dp);
        return rec(a, 0);
    }
};