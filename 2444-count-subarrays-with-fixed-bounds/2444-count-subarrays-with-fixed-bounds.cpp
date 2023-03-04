class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long int ans=0;
        int tempmaxind=-1;
        int tempminind=-1;
        int lastinvalid=-1;
        for(int i=0;i<nums.size();i++){
         if(nums[i]>=minK && nums[i]<=maxK){
             if(nums[i]==minK) tempminind=i;
             if(nums[i]==maxK) tempmaxind=i;
             ans+=max(0,min(tempmaxind,tempminind)-lastinvalid);
         }
         else{
             lastinvalid=i;
             tempminind=-1;
             tempmaxind=-1;
         }
        }
        return ans;
    }
};