class Solution {
public:
    int minDeletion(vector<int>& nums) {
        int ans=0;
        int i;
        for(i=0;i<nums.size()-1;i++)
        {
                if(nums[i]==nums[i+1] and (i-ans)%2==0)
                    ans++;
        }
        if((nums.size()-ans)%2 !=0)
            return ++ans;
        
        return ans;
    }
};