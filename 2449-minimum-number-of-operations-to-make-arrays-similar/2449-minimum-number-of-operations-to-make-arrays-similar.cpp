class Solution {
public:
    long long makeSimilar(vector<int>& nums, vector<int>& target) {
       vector<int> even1, even2;
        vector<int> odd1, odd2;
        
        sort(nums.begin(), nums.end());
        sort(target.begin(), target.end());
        
        for (int i=0; i<nums.size(); i++) {
            if (nums[i]%2) odd1.push_back(nums[i]);
            else even1.push_back(nums[i]);
            
            if (target[i]%2) odd2.push_back(target[i]);
            else even2.push_back(target[i]);
        }
        
        long long res=0;
        for (int i=0; i<even1.size(); i++) {
            if (even1[i]<even2[i])
                res+=(even2[i]-even1[i])/2;
        }
        for (int i=0; i<odd1.size(); i++) {
            if (odd1[i]<odd2[i])
                res+=(odd2[i]-odd1[i])/2;
        }
        
        return res; 
    }
};