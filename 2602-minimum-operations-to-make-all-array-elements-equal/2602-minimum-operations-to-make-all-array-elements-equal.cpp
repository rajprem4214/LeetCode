#define ll long long

class Solution {
public:
    vector<long long> minOperations(vector<int>& nums, vector<int>& queries) {
        vector<ll> ans;
        sort(nums.begin(), nums.end());
        
        ll n = nums.size();
        vector<ll> prefix(n+1, 0);
        for(int i = 1; i <= n; i++) {
            prefix[i] = nums[i-1] + prefix[i-1];
        }
        
        for(auto &it: queries) {
            int pos = lower_bound(nums.begin(), nums.end(), it) - nums.begin();
            if(pos == n) {
                ll res = abs((n * it) - prefix[n]);
                ans.push_back(res);
            } 
            else if(nums[pos] == it) {
                ll lsize = pos, rsize = n - 1 - pos;
                ll p1 = abs((lsize * it) - prefix[pos]);
                ll p2 = abs((rsize * it) - (prefix[n] - prefix[pos] - it));
                ans.push_back(p1 + p2);
            }
            else {
                ll lsize = pos, rsize = n - pos;
                ll p1 = abs((lsize * it) - prefix[pos]);
                ll p2 = abs((rsize * it) - (prefix[n] - prefix[pos]));
                ans.push_back(p1 + p2);
            }
        }
        
        return ans;
    }
};