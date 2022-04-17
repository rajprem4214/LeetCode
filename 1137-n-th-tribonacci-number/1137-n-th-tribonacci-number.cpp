class Solution {
    int dp[38];
public:
    int tribonacci(int n) {
        if(n<3) return n==0 ? 0 : 1;
        if(!dp[n]) dp[n] = tribonacci(n-3)+tribonacci(n-2)+tribonacci(n-1);
        return dp[n];
    }
};