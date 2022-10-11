class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
       int n = nums.size();
        
        int one = nums[0], two = INT_MAX;
        for (int i = 1; i < n; i++) {
            if (nums[i] > one && nums[i] > two)
                return true;
            if (nums[i] > one)
                two = nums[i];
            else one = nums[i];
        }
        
        return false;
        
        
    }
};