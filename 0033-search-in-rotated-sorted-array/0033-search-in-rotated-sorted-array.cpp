class Solution {
public:
    int search(vector<int>& nums, int target) {
        //logn
        int low=0;
        int high=nums.size()-1;
        while(low<=high)
        {
            int mid=low+(high-low)/2;

            if(nums[mid]==target)
            return mid;

            //identify the sorted part

            //if left part is sorted
            if(nums[low]<=nums[mid])
            {
                if(nums[low]<=target && target<=nums[mid])
                high=mid-1;
                else
                low=mid+1;
            }

            //if right part is sorted
            else
            {
                if(nums[mid]<=target && target<=nums[high])
                low=mid+1;
                else 
                high=mid-1;
            }
        }
    return -1;
    }
};