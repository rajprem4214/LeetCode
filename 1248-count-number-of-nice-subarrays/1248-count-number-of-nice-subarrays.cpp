class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        
        int count = 0;
        
        for(int i = 0; i < n; i++)
        {
            if(nums[i] % 2)
            {
                nums[i] = 1;
            }
            
            else
            {
                nums[i] = 0;
            }
        }
        
        unordered_map<int, int> mp;
        
        mp[0] = 1;
        
        int curr_sum = 0;
        
        for(int i = 0; i < n; i++)
        {
            curr_sum += nums[i];
            
            int need = curr_sum - k;
            
            if(mp.count(need))
            {
                count += mp[need];
            }
            
            mp[curr_sum]++;
        }
        
        return count;
    }
};