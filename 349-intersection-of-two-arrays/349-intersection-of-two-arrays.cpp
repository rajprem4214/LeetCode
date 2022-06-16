class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int> ans;
        vector<int> v;
        unordered_map<int,int> m;
        
        for(int i=0;i<nums1.size();i++){
            m[nums1[i]]++;
        }
        
        for(int i=0;i<nums2.size();i++){
            if(m.find(nums2[i]) != m.end())
                ans.insert(nums2[i]);
        }
        for(auto i: ans)
            v.push_back(i);
        
        return v;
        
    }
};