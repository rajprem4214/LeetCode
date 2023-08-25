class Solution {
public:
    void merge(vector<int> &nums, int low, int mid, int high) {
        vector<int> temp; // temporary numsay
        int left = low;      // starting index of left half of nums
        int right = mid + 1;   // starting index of right half of nums

        //storing elements in the temporary numsay in a sorted manner//
        while (left <= mid && right <= high) {
            if (nums[left] <= nums[right]) {
                temp.push_back(nums[left]);
                left++;
            }
            else {
                temp.push_back(nums[right]);
                right++;
            }
        }
        // if elements on the left half are still left //
        while (left <= mid) {
            temp.push_back(nums[left]);
            left++;
        }
        //  if elements on the right half are still left //
        while (right <= high) {
            temp.push_back(nums[right]);
            right++;
        }
        // transfering all elements from temporary to nums //
        for (int i = low; i <= high; i++) {
            nums[i] = temp[i - low];
        }
    }
    
    int countPairs(vector<int> &nums, int low,int mid, int high) {
        int right=mid+1;
        int cnt=0;
        for(int i=low;i<=mid;i++) {
            while(right<=high && nums[i]> 2* (long long) nums[right])
                ++right;
            cnt += (right-(mid+1));
        }
        return cnt;
    }
    int mergeSort(vector<int>& nums, int low, int high) {
        int count = 0;
        if (low >= high) 
            return 0;
        int mid = (low + high) / 2 ;
        count += mergeSort(nums, low, mid);
        count += mergeSort(nums, mid + 1, high);
        count += countPairs(nums, low, mid, high);
        merge(nums, low, mid, high);
        return count;
    }
    int reversePairs(vector<int>& nums) {
        return mergeSort(nums, 0, nums.size()-1);
    }
};