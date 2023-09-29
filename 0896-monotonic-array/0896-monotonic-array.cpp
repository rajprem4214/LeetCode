class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        vector<int> v = nums;
        sort(v.begin(), v.end());
        if(v == nums)
            return true;
        
        sort(v.begin(), v.end(), greater<int>());
        if(v == nums)
            return true;
        
        return false;
    }
};