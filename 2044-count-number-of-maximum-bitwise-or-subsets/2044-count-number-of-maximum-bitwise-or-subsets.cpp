class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int mx = 0;
        for (auto num : nums) mx |= num;
        vector<int> subset;
        int result = subsets(nums, 0, nums.size(), subset, mx);
        return result;
    }
    int subsets(vector<int> &nums, int i, int n, vector<int> &subset, int mx) {
        if (i >= n) {
            int a = 0;
            for (auto num : subset) a |= num;
            if (a == mx) return 1;
            else return 0;
        }
        int temp1 = subsets(nums, i+1, n, subset, mx);
        subset.push_back(nums[i]);
        int temp2 = subsets(nums, i+1, n, subset, mx);
        subset.pop_back();
        return temp1 + temp2;
    }
};