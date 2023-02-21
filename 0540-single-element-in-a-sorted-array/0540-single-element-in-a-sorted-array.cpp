class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        
        int low = 0;
        int high = n-1;
        int val=0;
        while(low<=high)
        {
            int mid = (low + high)/2;
            if(mid == 0 || mid == n)
            {
                val = nums[mid];
                break;
            }
            
            if(mid % 2 ==0)
            {
                if(nums[mid]==nums[mid-1])
                    high = mid;
                else if(nums[mid] == nums[mid+1])
                    low = mid+1;
                else
                    return nums[mid];
                
            }
            else {
                if(nums[mid] == nums[mid-1])
                    low = mid+1;
                else if(nums[mid] == nums[mid+1])
                    high = mid;
                else 
                    return nums[mid];
            }
            
        }
        return val;
    }
};