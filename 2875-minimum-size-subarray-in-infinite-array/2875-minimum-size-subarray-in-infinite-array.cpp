class Solution {
public:
    int minSizeSubarray(vector<int>& nums, int target) {
         vector<int>temp=nums;
        for(int i=0;i<nums.size();i++)temp.push_back(nums[i]);
        long long sumNums=0;
        for(int i=0;i<nums.size();i++)sumNums+=nums[i];
        
        int q=target/sumNums;
        int rem=target%sumNums;
        if(!rem)
        {
            return q*nums.size();
        }
        target=rem;
        int ans=1e9;
        int j=0;
        long long sum=0;
        for(int i=0;i<temp.size();i++)
        {
            sum+=temp[i];
            while(sum>target)
            {
                sum-=temp[j++];
            }
            if(sum==target)
            {
                ans=min(ans,i-j+1);
            }
        
        }
        if(ans!=1e9)
        {
            return q*nums.size()+ans;
        }
        return -1;
    
    }
};