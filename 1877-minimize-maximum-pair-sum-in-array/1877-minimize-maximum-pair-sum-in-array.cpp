class Solution {
public:
    int minPairSum(vector<int>& nums) {
        vector<int>v;
    sort(nums.begin(),nums.end());
    int i=0,j=nums.size()-1;
    while(i<j)
    {
        v.push_back(nums[i]+nums[j]);
        i++;
        j--;
    }
    return *max_element(v.begin(),v.end());
}
};