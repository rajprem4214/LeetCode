class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int result = 0;
        int sum = 0;
        xor_sum(result, nums, 0, sum);
        return result;
    }
    
    void xor_sum(int& result, vector<int>& nums, int idx, int sum){
        result += sum;
        for (int i = idx; idx < nums.size(); ++idx){
            sum ^= nums[idx];
            xor_sum(result, nums, idx + 1, sum);
            sum ^= nums[idx];
        }
    }
};