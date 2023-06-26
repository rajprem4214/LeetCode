class Solution {
public:
    typedef pair<int, int> pi;
    long long totalCost(vector<int>& costs, int k, int c) {
        int n = costs.size(),start = 0,end = n-1;

         long long max_cost = 0;
         priority_queue<pi, vector<pi>, greater<pi> > pq1;
         priority_queue<pi, vector<pi>, greater<pi> > pq2;
         
         while(start <= end && k > 0){
             
         if(pq1.size() < c) pq1.push({costs[start],start++});
         if(pq2.size() < c) pq2.push({costs[end],end--});

  while((pq1.size() == c && pq2.size() == c) || (start > end && k > 0 && (!pq1.empty()|| !pq2.empty()))){
            
             if(!pq1.empty() && pq2.empty()){
                max_cost = max_cost + pq1.top().first;
                 pq1.pop();
             }
              else if(pq1.empty() && !pq2.empty()){
                max_cost = max_cost + pq2.top().first;
                 pq2.pop();
             }
             else if(pq1.top().second == pq2.top().second){
                 max_cost = max_cost + pq1.top().first;
                 pq1.pop();
                 pq2.pop();
             }
             else if(pq1.top().first <= pq2.top().first){
                 max_cost = max_cost + pq1.top().first;
                 pq1.pop();
             }
             else {
                 max_cost = max_cost + pq2.top().first;
                 pq2.pop();
             }
              k--;
         }      
    }

        return max_cost; 
    }
};