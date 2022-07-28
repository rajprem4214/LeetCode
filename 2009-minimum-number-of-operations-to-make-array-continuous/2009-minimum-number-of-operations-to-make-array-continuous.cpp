class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        set<int> s;
        for(auto& a: nums) s.insert(a);
        int uni = s.size();
		// Find the occurances of duplicates, for those duplicates, we have to change them.
        int dup = n - uni;
        
        vector<int> v;
        for(auto& a: s) v.push_back(a);
        
        int ans = n-1;
		// The vector v contains unique elements in nums. 
		// For each element in v, we can choose that element as the start of the sequence, and count how many elements in v are already in the sequences (we don't need to change those elements). For the rest of the elements in v, we need to modify them.
        for(int i=0; i<uni; ++i) {
            int s = v[i], e = v[i] + n- 1;
            auto it1 = lower_bound(v.begin(), v.end(), s);
            auto it2 = upper_bound(v.begin(), v.end(), e);
            int coverage = it2 - it1;
            ans = min(ans, uni - coverage);
        }
        return ans + dup;
    }
};