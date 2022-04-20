class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
         int first=0,last=nums.size()-1;
    int count=0;
    for(int i=0;i<nums.size();i++){
        if(nums[i]==val){
            nums[i]=-1;
            ++count;
        }
    } 
    sort(nums.begin(),nums.end(),greater<>());
    count=nums.size()-count;
    return count; 
    }
};