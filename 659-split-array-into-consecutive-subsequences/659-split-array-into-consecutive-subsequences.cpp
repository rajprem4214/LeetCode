class Solution {
public:
    bool isPossible(vector<int>& nums) {
        map<int,int> left, end;
        for(auto num: nums) ++left[num];
        for(auto num: nums){
            if(left[num]==0) continue;
            
            if(end[num-1]>0){
                --left[num];
                --end[num-1];
                ++end[num];
            }
            else {
                if(left[num+1]==0 || left[num+2]==0) return false;
                --left[num];
                --left[num+1];
                --left[num+2];
                ++end[num+2];
            }
        }
        return true;
    }
};