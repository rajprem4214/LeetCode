class Solution {
public:
    int count = 0;
    void findWays(vector<int>& nums, int target,int start,int sum){
       if(start == nums.size() && sum == target){
           count++;
           return;
       }
        if(start >= nums.size()){
            return;
        }
        findWays(nums, target, start + 1, sum + nums[start]);
        findWays(nums, target, start + 1 ,sum - nums[start]);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        findWays(nums, target,0,0);
        return count;
    }
};