class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        
        unordered_map<int,int> m;
        for(int i=0;i<nums.size();i++){
            m[nums[i]]++;
            
        }
        int ans=0;
        for (const std::pair<int, int>& p : m)
        {
            ans += (p.second * (p.second - 1)) / 2;
        }
        return ans;
        
    }
};