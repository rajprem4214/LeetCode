class Solution {
public:
    int longestEqualSubarray(vector<int>& nums, int k) {
        unordered_map<int,int> m;
        int l=0, mxLen = 0;
        for(int i=0;i<nums.size();i++)
        {
            m[nums[i]]++;
            mxLen = max(mxLen, m[nums[i]]);
            
            int mxDiff = i-l+1-mxLen;
            if(mxDiff > k)
            {
                m[nums[l]]--;
                l++;
            }
        }
        return mxLen;
    }
};