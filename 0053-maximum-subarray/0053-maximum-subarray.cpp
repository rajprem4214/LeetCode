class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int s = 0;
        if(nums.size() == 1)
            return nums[0];
            int ans = -1e9;
        for(int i=0;i<nums.size();i++)
        {
            s+=nums[i];
             ans = max(ans,s);
            if(s < 0)
                s= 0;
            
           
        }
        return ans;
    }
};