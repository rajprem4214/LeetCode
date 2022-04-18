class Solution {
public:
    void wiggleSort(vector<int>& nums) {
      sort(nums.begin(),nums.end());
        vector<int>ans;
        int n=nums.size()-1;
        int m=n/2;
        int x=m;
        while(m>=0)
        {
            ans.push_back(nums[m--]);
            if(n>x)
               ans.push_back(nums[n--]);
        }
        nums=ans;
    }
};