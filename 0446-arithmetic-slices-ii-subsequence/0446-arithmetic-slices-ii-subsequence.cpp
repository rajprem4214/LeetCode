class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
         int n=nums.size();
        if(n<3)
        return 0;
        vector<unordered_map<long,long>>dp(n);
        int res=0;
        for(int i=1;i<n;i++)
        {    
            for(int j=0;j<i;j++)
            {
                long cd=long(nums[i])-long(nums[j]);
                
                res+=dp[j][cd];
                dp[i][cd]+=dp[j][cd];
                dp[i][cd]++;
            } 
        }
        return res;
    }
};