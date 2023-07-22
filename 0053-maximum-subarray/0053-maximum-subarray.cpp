class Solution {
public:
    int maxSubArray(vector<int>& nums) {
       int curr_sum = 0;
        int flag = 0;
    int ans = INT_MIN; 
        if(nums.size()==1)
            return nums[0];
        for(int i=0;i<nums.size();i++)
        {
            curr_sum += nums[i];
              ans = max(ans, curr_sum);
            if(curr_sum < 0)
                curr_sum = 0;
            
          
        }
        return ans;
    }
};