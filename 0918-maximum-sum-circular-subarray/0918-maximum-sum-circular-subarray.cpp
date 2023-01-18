class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        // find the max and the minimum and the total sum
        int totalSum = nums[0];
        int maxValue = nums[0];
        int minValue = nums[0];
        vector<int> maxArray (nums.size(),0);
        vector<int> minArray (nums.size(),0);
        maxArray[0] = nums[0];
        minArray[0] = nums[0];
        for(int i =1;i < nums.size();i++)
        {
            maxArray[i] = max(maxArray[i-1]+nums[i],nums[i]);
            minArray[i] = min(minArray[i-1]+nums[i],nums[i]);
            maxValue = max(maxArray[i],maxValue);
            minValue = min(minArray[i],minValue);
            totalSum += nums[i];
        }
        if(totalSum != minValue)
        return max(maxValue,totalSum-minValue);
        return maxValue;

    }
};