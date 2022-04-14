class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int low = 0;
        int high = nums.size() - 1;
        
        // handling corner case of array having only one element
        if(nums.size() == 1) return 0;
        
        while(low <=  high) {
            int mid = low + (high - low) / 2;
            
            // if we are at the begning we can compare with the next element only
            if(mid == 0) {
                if(nums[mid] > nums[mid + 1]) return mid; else low = mid + 1;
            // if we are at the end we can compare with last second element only
            } else if(mid == nums.size()-1) {
                if(nums[mid] > nums[mid - 1]) return mid; else high = mid - 1;
            } else {
                // if the current element is peak return the index
                if(nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1]) return mid;
                // if the next element is bigger so we will go left as we need only one more element to be in right of bigger element
                else if(nums[mid + 1] > nums[mid]) {
                    low = mid + 1;
                // same case as above to element before
                } else if(nums[mid - 1] > nums[mid]) {
                    high = mid - 1;
                }
            }
         }
        
        return -1;
    }
};