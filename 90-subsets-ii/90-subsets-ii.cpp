class Solution {
public:
         void solve(int ind, vector<int>&nums , vector<vector<int>>&ans,vector<int>&v){
            ans.push_back(v);
             
             for(int i=ind;i<nums.size();i++){
                 if(i!=ind && nums[i] == nums[i-1])
                     continue;
                 v.push_back(nums[i]);
                 solve(i+1,nums,ans,v);
                 v.pop_back();
             }
            
             
         }
    
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
         
        vector<int>v;
        sort(nums.begin(),nums.end());
        solve(0,nums,ans,v);
        return ans;
    }
};