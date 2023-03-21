#define ll long long
class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        ll n = nums.size();
        long long ans = 0;
        ll cnt = 0;
        for(ll i=0;i<n;i++)
        {
            if(nums[i] == 0)
            {
                cnt++;
            }
            else
            {
               ans += (cnt)*(cnt+1)/2;
                cnt=0;
            }
            
                // cnt++;
        }
        if(cnt > 0)
            ans+=(cnt)*(cnt+1)/2;
        return ans;
    }
};