class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        // int mul = INT_MIN;
        int n = nums.size();
        int curr=0;
        int ans = 0;
        int mx = *max_element(nums.begin(),nums.end());
        int rest = 0;
        cout<<mx;
        for(auto i:nums)
        {
            // while(j<n && nums[i])
         if(i==mx)
             curr++;
            else
            {
                rest =max(rest,curr);
                curr=0;
            }
            
        }
        rest = max(rest,curr);
        
        return rest;
    }
};