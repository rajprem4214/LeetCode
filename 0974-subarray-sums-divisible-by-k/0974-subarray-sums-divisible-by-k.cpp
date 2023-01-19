class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
          int n = nums.size(), i, ans = 0;
        vector <int> pre(n, 0);
        unordered_map <int, int> mp;
        mp[0]++;
        for (i=0;i<n;i++) {
            if (i == 0)
            pre[i] = nums[i]%k;
            else
            pre[i] = (pre[i-1] + nums[i])%k;
            pre[i] = pre[i] < 0 ? pre[i] + k : pre[i];
            mp[pre[i]]++;
        }
        for (auto x : mp)
        ans += (x.second*(x.second-1))/2;
        return ans;
    }
};