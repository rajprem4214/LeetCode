class Solution {
public:
    int sdig(int n){
        int ans=0;
        string s = to_string(n);
        for(auto x:s)
            ans+= x-'0';
        return  ans;
    }
    
    int maximumSum(vector<int>& nums) {
        vector<int> sum;
        for(int i=0;i<nums.size();i++){
            sum.push_back(sdig(nums[i]));
        }
        
        unordered_map<int,vector<int>> m;
        
        for(int i=0;i<sum.size();i++){
            m[sum[i]].push_back(nums[i]);
        }
        int f=0;
        int ans = 0;
        vector<int> v;
        for(auto x:m)
        {
            v=x.second;
          if(v.size() != 1)
          {
              f=1;
              sort(v.begin(),v.end());
              int l =v.size();
              ans = max(ans,v[l-1]+v[l-2]);
          }
        }
        if(!f)
            return -1;
        else
            return ans;
    }
};