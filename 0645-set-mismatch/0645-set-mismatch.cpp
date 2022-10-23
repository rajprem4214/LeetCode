class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        long long sum=0;
        vector<int> freq(nums.size());
        vector<int> res;
        for(int i=0; i<nums.size(); i++){
            freq[nums[i]-1]++;
            sum+=nums[i];
            if(freq[nums[i]-1]>1) res.push_back(nums[i]);
        }
        res.push_back((nums.size()*(nums.size()+1)/2)-sum+res[0]);
        return res;
    }
};