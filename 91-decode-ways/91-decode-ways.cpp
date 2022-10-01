class Solution {
public:
    int ans, n;
    int dp[101];
    
    int solve(string &s, int p)
    {
		// if pointer come at the end therefore a way exist
        if(p == n)
            return 1;
			
		// leading zero not allowed
        if(s[p] == '0')
            return 0;
        
		// if there exist a pre calcutated ans then return
        if(dp[p] != -1)
            return dp[p];
        
		// move the pointer 1 step forward
        int ans = solve(s, p+1);
        
		// if the first character is 1 then move the pointer 2 step
        if(s[p] == '1' and p+1 < n)
            ans += solve(s, p+2);
        
		// if the first character is 2 and next character is less than equal to 6
        if(s[p] == '2' and p+1 < n and s[p+1] <= '6')
            ans += solve(s, p+2);
        
        return dp[p] = ans;
    }
        
    int numDecodings(string s) {
        ans = 0;
        n = s.length();
        memset(dp, -1, sizeof(dp));
        
        return solve(s, 0);        
    }
};