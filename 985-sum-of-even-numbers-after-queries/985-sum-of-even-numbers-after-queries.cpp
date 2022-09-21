class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int> ans;
        int n = nums.size();
        
        int sum = 0;
        for(int i=0;i<n;i++)
            if(nums[i]%2==0)
                sum+=nums[i];
       
        for(int i=0;i<queries.size();i++)
        {
            int val=queries[i][0];
        int index=queries[i][1];
        int oldvalue=nums[index];
        nums[index]+=val;
        bool waseven = (oldvalue % 2) == 0;
            bool noweven = (nums[index] % 2 == 0);
     if(waseven && noweven)
     {
         sum+=val;
         ans.push_back(sum);
     }
         else if(waseven && !noweven)
         {
             ans.push_back(sum-oldvalue);
             sum-=oldvalue;
         }
         else if(!waseven && noweven)
         {
             ans.push_back(sum+nums[index]);
             sum+=nums[index];
         }
         else{
             ans.push_back(sum);
         }
    }
       return ans; 
       
    }
};