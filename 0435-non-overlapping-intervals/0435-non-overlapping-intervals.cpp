class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
       sort(intervals.begin(), intervals.end());
        int count = 0;
        int prev = intervals[0][1];
        for(int i=1; i<intervals.size(); i++){
            if(prev > intervals[i][0]){
                count++;
                prev = min(intervals[i][1],prev);
            }else prev = intervals[i][1];
            
        }
        return count;
    }
};