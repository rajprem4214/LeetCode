class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int l=0;
        int r=nums.size()-1;
        
          if(target > nums[nums.size()-1]){
            return nums.size();
        }
        if(target < nums[0]){
            return 0;
        }
        while(l <= r){
            int m = l + (r-l)/2;
            
            if(nums[m] == target)
                return m;
            
            if(nums[m]<target)
                l=m+1;
            else
                r=m-1;
        }
        return l;
    }
};