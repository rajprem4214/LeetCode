class Solution {
public:
    void sortColors(vector<int>& nums) {
     int  n = nums.size();
        // via dutch national flag algotithm
        int low = 0, mid = 0, high = n-1;
        
        while(mid <= high) // condition to check array will be sorted
        {
            if(nums[mid] == 0)
            {
                swap(nums[mid], nums[low]);
                low++;
                mid++;
            }
            else if(nums[mid] == 1)
            {
                mid++;
            }
            else{
                swap(nums[mid], nums[high]);
                high--;
            }
        }
    }
};