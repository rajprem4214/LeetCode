class Solution {
public:
    int countPairs(vector<vector<int>>& nums, int k) {
          map<pair<int,int>,int> mp;
        int n=nums.size();
        int ans=0;
        for(int i=0 ; i<n ; i++){
            

            for(int val=0 ; val<=k ; val++){

                
                int x=val^nums[i][0];    
                int y=(k-val)^nums[i][1];
                ans+=mp[make_pair(x,y)];
            }
            
            mp[make_pair(nums[i][0],nums[i][1])]++;
        }
        return ans;
    }
};