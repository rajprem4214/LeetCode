class Solution {
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        
//         Approach using Binary Search: T.C -> O(N(Log(mx)))
        
        //taking max value from nums to set the upper limit of penalty can reach
        int mx = *max_element(nums.begin(), nums.end());
        
        // set start = 1 because lowest penalty can possible is 1
        // set end = mx highest penalty can possible is mx
        int start = 1, end = mx;
        
        // initialize the ans as 0
        int ans = 0;
        
        while(start <= end){
            
            // calculate the mid
            int mid = start + (end - start)/2;
            
            int totOper = 0;
            
            // count the possible bags that can be divided into small bags by mid
            
            for(int &i: nums){
            
                // check if remainder is 0 then possible operations will be (i/mid - 1) because:
                    // if we divide 12 in 4 parts of 3 each then we will cut the 12 three times 3 - 3 - 3 and 
                    // last part will be 3. so total operations will be 3...
                
                if(i % mid == 0){
                    totOper += (i/mid - 1);
                }
                
                // if the value is not the multiple of mid then remainder will be extra and kept in a new bag
                // thats why we will not delete 1.
                else{
                    totOper += i/mid;
                }
            }
            
            // check if the Total Operations <=  maxOperations then we will update the ans
            // and start the search for smaller values;
            
            if(totOper <= maxOperations){
                ans = mid;
                end = mid - 1;
            }
            //if it is doesn't fullfill the condition then search for bigger values in possible limits 1 to mx
            else{
                start = mid + 1;
            }
        }
        return ans;
    }
};