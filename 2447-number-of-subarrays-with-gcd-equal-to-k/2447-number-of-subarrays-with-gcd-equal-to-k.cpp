
class Solution {
    #define ll long long
public:
    int subarrayGCD(vector<int>& nums, int k) {
        int ans = 0;
        int p=0;
        int n = nums.size();
        p++;
        for(int i=0; i<n; i++){
            int curr = 0;
            // p+=ans;

            for(int j=i; j<n; j++){
                curr = __gcd(curr, nums[j]);
// p+=ans;
                ans += (curr == k) ? 1 : 0;
            }
        }
        return ans;
        
    }
};