class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) { 
        if( stations.empty()) return startFuel >= target ? 0 : -1;   
        priority_queue<int>pq;
        int cnt = 0;
        for(auto & it : stations){
            if(startFuel>=it[0]){
                pq.push(it[1]);
            }else{
                if(pq.empty())return -1;
                while(!pq.empty() and startFuel < it[0]){
                    cnt++;
                    startFuel += pq.top(); pq.pop();
                }
                if(startFuel >= it[0]){
                    pq.push(it[1]);
                }else return -1;
            }
        } 
        while(!pq.empty()){
            if( startFuel < target){
                startFuel += pq.top();
                pq.pop();
                cnt++;
            }else break;
        }
        if( startFuel < target)return -1;
        else return cnt;
    }
};