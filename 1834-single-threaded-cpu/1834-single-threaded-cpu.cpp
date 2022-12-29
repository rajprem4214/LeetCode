class Solution {
public:
// static bool comp(vector<int>& a,vector<int> b){
//     if(a[0]==b[0])
//     return a[2]<b[2];
//     else
//     return a[0]<b[0];
// }
    vector<int> getOrder(vector<vector<int>>& tasks) {
        vector<int> sols;
        vector<vector<int>> tasks2=tasks;
        for(int po=0;po<tasks.size();po++){
          tasks2[po].push_back(po);
        }
        sort(tasks2.begin(),tasks2.end());
        int starts=tasks2[0][0];
        int ie=0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> po;
        while(ie<tasks2.size()){
            if(ie<tasks2.size()&&tasks2[ie][0]<=starts){
            while(ie<tasks2.size()&&tasks2[ie][0]<=starts){
                po.push({tasks2[ie][1],tasks2[ie][2]});
            ie++;}
                        if(po.size()){
                 pair<int,int> starts2=po.top();
            po.pop();
            sols.push_back(starts2.second);
            //999999999
            starts+=starts2.first;
            }
        }
            else
            {
            while(po.size()&&starts<tasks2[ie][0]){
                 pair<int,int> starts2=po.top();
            po.pop();
            sols.push_back(starts2.second);
            //999999999
            starts+=starts2.first;
            }
            if(starts<tasks2[ie][0])
            starts=tasks2[ie][0];}
        } 
        while(po.size()){
            sols.push_back(po.top().second);
            po.pop();
        }
        return sols;
    }
};