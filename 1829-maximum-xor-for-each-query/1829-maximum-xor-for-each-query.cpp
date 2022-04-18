class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
            int n = nums.size();
          int xr = 0;
       
        
        for(int i=0;i<nums.size();i++){
            xr = xr ^ nums[i]; 
        }
        
        vector<int> ans;
        int x = pow(2,maximumBit) - 1;
      
       for(int i=n-1;i>=0;i--){
           
           ans.push_back(xr^x);
           
           xr = xr ^ nums[i];
           
       }
        
        return ans;
        
        
    }
};