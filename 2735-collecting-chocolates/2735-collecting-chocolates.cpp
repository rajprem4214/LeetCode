class Solution {
public:
    long long minCost(vector<int>& nums, int x) {
        long long int ans = 0;
        int n = nums.size();
        // Store then minimum value for ith chocolate
        vector<int> arr = nums;
        for(int i=0;i<n;i++){
            ans += nums[i];
        }
        int k = n-1;
        long long int rot = x;
        // k is for all the rotation
        while(k--){
            // Roation start
            int temp = nums[0];
            for(int i=0;i<n-1;i++){
                nums[i] = nums[i+1];
            }
            nums[n-1] = temp;
            // Rotation end

            // Update the best result for each chocolate after rotation
            long long int sum = 0;
            for(int i=0;i<n;i++){
                arr[i] = min(arr[i], nums[i]);
                sum += arr[i];
            }

            // Add the rotation cost
            sum += rot;
            rot += x;

            // Update answer
            ans = min<long long int>(ans, sum);
        }
        return ans;
    }
};