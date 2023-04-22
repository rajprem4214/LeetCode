class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int> hashset;
        for(auto num: nums){
            hashset.insert(num);
        }
        int longestLen = 0;
        for(int i=0;i<nums.size();i++){
            if(!hashset.count(nums[i]-1)){
                int currLen = 1;

                while(hashset.count(nums[i]+1)){
                    nums[i]=nums[i]+1;
                    currLen++;
                }
                longestLen = max(longestLen, currLen);
            }
        }
        return longestLen;
    }
};