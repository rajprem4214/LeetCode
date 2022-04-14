class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0, high = nums.size() - 1;
        
        while(low < high)
        {
            int mid = low + (high - low)/2;
			
			// if low, mid and high are all the same
            // then we could simply shorten the search space by 1 each on both ends
            // because the inflexion point must lie within those bounds
            // so correctness of the algorithm is not impacted by shrinking the array
			
            if(nums[low] == nums[mid] && nums[mid] == nums[high])
            {
                ++low;
                --high;
            }
            else if(nums[mid] > nums[high])
            {
                low = mid + 1;
            }
            else if(nums[mid] <= nums[high])
            {
                high = mid;
            }
        }
        
        return nums[low];
    }
};