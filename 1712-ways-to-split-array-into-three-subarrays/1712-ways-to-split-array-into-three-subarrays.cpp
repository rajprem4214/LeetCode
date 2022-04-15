class Solution {
public:
    int waysToSplit(vector<int>& nums) {
     int n = nums.size();
        
        // generate prefix sum
        for(int i=1;i<n;i++)nums[i]+=nums[i-1];
        
        int left  = 0;  // last pointer of first part
        int mid = 1;    // first pointer of middle part
        int right = 2;  // last pointer of middle part
        int count = 0;
        
        // loop through array and find the mid and right for each left pointer
        // as left pointer moves forward, mid and right pointer moves forward too
        while(left < n-2)
        {
            mid = max(mid,left+1);
            
            // move mid forward as long as sum till mid < 2 * sum till left  
            // goal is to find the minimum pointer of middle part for current left part
            while(mid<n-1 && nums[mid]<2*nums[left])mid++;
            
            right = max(mid,right);

            // move right forward as long as mid part sum <= right part sum
            // goal is to find the maximum pointer of middle part for current left part
            while(right<n-1 && nums[right]-nums[left]<=nums[n-1]-nums[right])right++;
            
            count = (count + right - mid) % 1000000007;
            
            left++;
        }
        
        return count;   
    }
};