class Solution {
public:
vector<int> sortArrayByParity(vector<int>& nums) 
    {
        int put=0;
        for(int i=0;i<nums.size();i++) if(nums[i]%2==0) swap(nums[put++],nums[i]);
        return nums;
    }
};