class Solution {
public:
    int jump(vector<int>& nums) {
          int maxr=0, curreach=0, jump=0;
        
         for (int i=0; i< nums.size()-1; i++){
             
               maxr= max(maxr, i+nums[i]);
             
               if (i == curreach){
                  curreach= maxr;
                     jump ++;  
                   
               }
                  
         }
        
           return jump;
    }
};