class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& numsDivide) {
        int g=numsDivide[0];
        for(int i=1;i<numsDivide.size();i++){
            g = __gcd(g,numsDivide[i]); 
        }
        // set<int>s;
        int k=0;
       
        int ans = INT_MAX;
        int f=0 ;
        
        for(int i=0;i<nums.size();i++)
        {
            if(g%nums[i]==0)
                ans = min(ans,nums[i]);
        }
        
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i] == ans)
                f=1;
            if(nums[i] < ans)
               k++;
        }
        if(f)
            return k;
        else
            return -1;
        // return ans;
    }
};