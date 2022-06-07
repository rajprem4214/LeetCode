class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        priority_queue<pair<int,int>> vec;
        for(int i=0;i<nums.size();i++) vec.push({nums[i],i});
        priority_queue<pair<int,int>> vec2;
        for(int i=0;i<k;i++){
            vec2.push({vec.top().second,vec.top().first});
            vec.pop();
        }
        vector<int> ans(k);
        for(int i=k-1;i>=0;i--){
            ans[i]=vec2.top().second;
            vec2.pop();
        }
        return ans;
    }
};