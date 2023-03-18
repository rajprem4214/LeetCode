class Solution {
public:
    int maximizeGreatness(vector<int>& nums) {
         multiset<int>s;
        for(auto it:nums)
            s.insert(it);     // insert all values in multiset
        sort(nums.begin(),nums.end());  // sort the given array nums
        int ans=0;
        for(int i=0;i<nums.size();i++)
        {
            auto it=s.upper_bound(nums[i]);
            if(it==s.end())         // if upper bound for curr number does not exist in set then upper bound for higher
			                               // values also does not exist so break
                break;
            ans+=1;
            s.erase(s.find(*it));  // if exist then increase ans by 1 and delete this value from multiset
        }
        return ans;   
    }
};