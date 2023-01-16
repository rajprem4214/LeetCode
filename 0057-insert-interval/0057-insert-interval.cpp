class Solution {
public:
    int search(vector<vector<int>>& intervals, int target, int pos) {
        int low = 0,high=intervals.size();
        while(low<high){
            int mid =low+((high-low)/2);
            if(intervals[mid][pos]==target)return mid;
            if(intervals[mid][pos]>target)high=mid;
            else low= mid+1;
        }
        if (pos==1)
            return low;        
        return low-1;  
    }
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;
        int start=search(intervals,newInterval[0],1);
        int end=search(intervals,newInterval[1],0);
        if (start<=end){
            newInterval[0]=min(newInterval[0],intervals[start][0]);
            newInterval[1]=max(newInterval[1],intervals[end][1]);
        }
        int i = 0;
        while(i<start)res.push_back(intervals[i++]);
        res.push_back(newInterval);
        i=end+1;
        while(i<intervals.size())res.push_back(intervals[i++]);
        return res;
    }
};