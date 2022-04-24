class Solution {
public:
    int minPairSum(vector<int>& nums) {
        vector<int>v;
    sort(nums.begin(),nums.end());
    int i=0,j=nums.size()-1;
        int m=INT_MIN;
    while(i<j)
    {
        m=max(m,nums[i]+nums[j]);
        i++;
        j--;
    }
    return m;
}
};