class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int left, right;
        int l = 0, r = n-1;
        int m;
        while(l<=r)
        {
            m = (l + r) / 2;
            if(target > nums[m])
                l = m + 1;
            else
                r = m - 1;
        }
        left = l >= 0 && l<= n-1 && nums[l] == target ? l : -1;
        l = 0, r = n-1;
        while(l<= r)
        {
            m = (l + r) / 2;
            if(target < nums[m])
                r = m - 1;
            else
                l = m + 1;
        }
        right = r >= 0 && r<n && nums[r] == target ? r : -1;
        
        return {left, right};
    }
};