class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int, vector<int>> pq;
        for(auto it : piles) pq.push(it);
        while(k--){
            int d = pq.top();
            pq.pop();
            if(d%2){
                d = d/2 +1;
            }
            else{
                d /= 2;
            }
            pq.push(d);
        }
        int ans =0;
        while(!pq.empty()){
            ans += pq.top();
            pq.pop();
        }
        return ans;
    }
};
