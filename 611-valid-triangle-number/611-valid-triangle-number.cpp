class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int n=nums.size();
        
        int ans=0;
        
        sort(nums.begin(),nums.end());
        
		/*taking left -> leftmost number  , mid -> middle element , right -> rightmost elemnt
        left is smallest one , mid -> middle element , right is largest one*/
        
        for(int right=n-1 ; right>=2 ;right--)
        {
            int left=0;
            int mid=right-1;
            while(left<mid)
            {
                
                 if(nums[left]+nums[mid]>nums[right])
                 {
                       ans+=(mid-left);
                       mid--;
                 }
                 else
                 {
                      left++;
                 }
            }
        }
        
        return ans;
    }
};