class Solution {
public:
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
         priority_queue<pair<int,int>>pq;
        int sum=0,ans=0;
        for(int i=0;i<plantTime.size();i++){
            pq.push({growTime[i],plantTime[i]});
        }
        while(!pq.empty()){
            sum+=pq.top().second;
            ans=max(ans,sum+pq.top().first);
            pq.pop();
        }
        return ans;
    }
};