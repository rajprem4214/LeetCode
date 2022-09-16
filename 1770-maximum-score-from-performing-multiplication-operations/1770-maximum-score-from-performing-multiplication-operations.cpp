class Solution {
public:
    int solve(int s,int e, int i,int &n, int &m, vector<int> &nums, 
              vector<int>& mul,vector<vector<int>> &dp){
        
        if(s>=m || m-(n-(e+1))<0 || i>=m || s>e) return 0; //base case
        
        if(dp[s][m-(n-(e+1))] != INT_MIN) return dp[s][m-(n-(e+1))];
        return dp[s][m-(n-(e+1))] = max(
                    (nums[s]*mul[i] + solve(s+1,e,i+1,n,m,nums,mul,dp))    // taking from start
                   ,(nums[e]*mul[i] + solve(s,e-1,i+1,n,m,nums,mul,dp)) ); // taking from end
    }
    int maximumScore(vector<int>& nums, vector<int>& mul) {
        int n = nums.size();
        int m = mul.size();
        // s&e for starting index and ending index of nums.
        int s=0,e=n-1,i=0;
        
        // we cannot create the dp of NxN as contraints of N are 1e5 so MLE will occur
        // so, if N is greater than m, then we can see that value of e will never
        // reach less than n-m and value of s will never increase above m
        // so we make the dp of MxM size to prevent MLE
        // so In DP our ending index will be (m - (n-(e+1)))
        // we create default value of DP as INT_MIN and not -1
        // because the MaxScore can be -1 so it will confuse with default value and give TLE
        vector<vector<int>> dp(m+1,vector<int>(m+1,INT_MIN));
        return solve(s,e,i,n,m,nums,mul,dp);
    }
};