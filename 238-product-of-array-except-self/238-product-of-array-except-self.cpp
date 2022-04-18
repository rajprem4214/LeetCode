class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans = {1};
        
        int prod = 1;
        for (int i = 1; i < n; i++) {
            prod *= nums[i-1];
            ans.push_back(prod);
        }
        
        prod = 1;
        for (int i = n-2; i >= 0; i--) {
            prod *= nums[i+1];
            ans[i] *= (prod);
        }
        
        return ans;
    }
};