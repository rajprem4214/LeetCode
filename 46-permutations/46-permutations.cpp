class Solution {
private:
    void f(vector<int>&nums, vector<vector<int>>&ans, int idx, int n){
        if(idx == n){
            //base case if idx becomes equal to nums sz then store it
            ans.push_back(nums);
            return;
        }
        for(int i = idx ;i<n;i++){
            swap(nums[i],nums[idx]);//swapping of itself
            f(nums, ans, idx+1,n);//swapping of curr with others
            swap(nums[i],nums[idx]);//for others
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>ans;
        f(nums,ans,0,n);
        return ans;
    }
};