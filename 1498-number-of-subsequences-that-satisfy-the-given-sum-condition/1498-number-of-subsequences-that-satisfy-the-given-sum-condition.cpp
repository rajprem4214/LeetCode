class Solution {
public:
    int MOD = 1e9+7;
    int numSubseq(vector<int>& nums, int target) {
        vector<int> powerof2(nums.size());
        powerof2[0]=1;
        for(int i=1;i<nums.size();i++){
            powerof2[i]=powerof2[i-1]*2%MOD;  //power of 2 in range of integer:
        }
     


         int cnt = 0;
        sort(nums.begin(),nums.end());
        int low = 0;
        int high = nums.size()-1;
        while(low<=high){
            if(nums[low]+nums[high]<=target){
                int k = high-low;
                cnt=(cnt%MOD+powerof2[k]%MOD)%MOD;
                low++;
            }
            else{
                high--;
            }
        }
        return cnt;
    }
};