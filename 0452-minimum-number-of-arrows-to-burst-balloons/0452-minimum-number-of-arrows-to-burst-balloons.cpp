class Solution {
  static  bool cmp(vector<int>&a , vector<int>&b){
        return a[1]<b[1];
    }
    
    public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(),points.end(),cmp);
       int count=1;
        int curMin = points[0][1];
        for(int i=1;i<points.size();i++) {
            if( points[i][0]>curMin){
                count++;
                curMin = points[i][1];
            } 
        }
        
        return count;
    }
};