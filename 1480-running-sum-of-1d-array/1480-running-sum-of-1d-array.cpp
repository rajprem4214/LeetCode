class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int>ans;
        
         int n=nums.size();
        int count =0;
        
        for(int i=0; i<n; i++){
            count += nums[i];
            ans.push_back(count);
        }
        return ans;
    }
};