class Solution {
public:
//     int f(int ind,vector<int>& nums,vector<int>&dp){
//         if(ind==0)
//             return nums[0];
//         if(ind<0)
//             return 0;
        
//         if(dp[ind] != -1)
//             return dp[ind];
        
//             int take = nums[ind] + f(ind-2,nums,dp);
//             int not_take = f(ind-1,nums,dp);
        
//         return dp[ind]= max(take, not_take);
//     }
    
    int rob(vector<int>& nums) {
        int n = nums.size();
         if(n==1) return nums[0];
        // vector<int> dp(n+1,-1);
        
          vector<int>dp(n,-1);
  dp[0]=nums[0];
  dp[1]=nums[1];
  dp[1]=max(dp[0],dp[1]);
  for(int i=2;i<n;i++){
    int incl=dp[i-2]+nums[i];
    int excl=dp[i-1]+0;
  dp[i]=max(incl,excl);
  }
  return dp[n-1];
    }
};