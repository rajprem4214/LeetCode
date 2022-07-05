class Solution {
public:
    int eatenApples(vector<int>& apples, vector<int>& days) {
         int n = days.size();   // apples.size()
        int day = 0;           //  note that apples will expire of ith day so starting from 0
        int ans = 0;           // max possible ans will be n as 1 per day
        
        //priority_queue to get latest expiring apple's date
        
        priority_queue<int,vector<int>,greater<int>>q;
        
        // unordered map will store no. of apples on a particular day available
        
        unordered_map<int,int>m;
        
        // though queue is empty; there might be further days where we can restock
        // so don't use and
        
        while(q.size() || day < n ){
            
            if(day<n && apples[day]!=0 && days[day]!=0){
                
                m[day + days[day]] += apples[day];     //add apples in stock
                q.push(day + days[day]);               // new deadline
                
            }
            
            while(q.size() && (q.top() <= day || m[q.top()]<=0) ){
                q.pop();             //  remove crossed or zero apples deadlines
            }
            
            // q's topmost can be consumed
            if(!q.empty()){
                ans++;
                m[q.top()]--;     //consumed
            }

            day++;
            
        }
        
        return ans;
        
    }
};