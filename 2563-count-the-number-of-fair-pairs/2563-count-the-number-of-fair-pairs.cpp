class Solution {
    long long solve(vector<int> &nums, int target) {
        int i = 0, j = nums.size() - 1;
        long long ans = 0;
        while(i < j) {
            while(i < j && nums[i] + nums[j] > target) {
                j--;
            }
            ans += j - i;
            i++;
        }
        return ans;
    }
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(), nums.end());
        return solve(nums, upper) - solve(nums, lower - 1);
    }
};