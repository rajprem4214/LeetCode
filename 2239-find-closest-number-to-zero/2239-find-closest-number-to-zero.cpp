class Solution {
public:
    int findClosestNumber(vector<int>& nums) {
     
        int ans1=INT_MIN;
        int ans2=INT_MAX;
        sort(nums.begin(),nums.end());
        
        for(int i=0;i<nums.size();i++){
            
            if(nums[i]<0)
              ans1= max(ans1,nums[i]);
            
            else if(nums[i]>=0)
                ans2= min(ans2,nums[i]);
                
        }
        
         if(ans1 != INT_MIN  && ans2==INT_MAX)
             return ans1;
        
        else if(ans1==INT_MIN && ans2 != INT_MAX)
            return ans2;
        
        else{
            if(abs(0-ans1)<abs(0-ans2))
                return ans1;
            else
                return ans2;
            
        }
            
            
    }
};