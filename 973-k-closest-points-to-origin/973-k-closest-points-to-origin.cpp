class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> ans;
        
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        pair<int,pair<int,int>>p;
        for(int i=0;i<points.size();i++){
            int d = pow(points[i][0], 2) + pow(points[i][1],2);
            p.first = d;
            p.second.first = points[i][0];
            p.second.second = points[i][1];
            pq.push(p);
        }
          
        while(k && !pq.empty()){
            vector<int> mid;
            int x = pq.top().second.first;
            int y = pq.top().second.second;
            
            mid.push_back(x);
            mid.push_back(y);
            
            ans.push_back(mid);
            pq.pop();
            k--;
        }
        
        return ans;
        
    }
};