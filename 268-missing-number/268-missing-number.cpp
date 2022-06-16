class Solution {
public:
    int missingNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int s=0;
        
        
        if(nums[0] != 0)
        {
         return 0;
        }
            
        
        for(int i=0;i<nums.size();i++)
        {
            s+=nums[i];
        }
        int p = nums[nums.size()-1];
        
        int psum = (p*(p+1))/2;
        
        if(psum == s)
            return p+1;
        
        else 
            return psum -s;
        
    }
};