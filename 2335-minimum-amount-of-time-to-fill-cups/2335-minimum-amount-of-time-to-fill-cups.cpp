class Solution {
public:
    int fillCups(vector<int>& amount) {
        priority_queue<int>pq;
        for(auto i:amount)if(i>0)pq.push(i);
        int ans=0;
        while(pq.size()>=2)
        {
            int one =pq.top();
            pq.pop();
            int two=pq.top();pq.pop();
            if(one>1)pq.push(one-1);
            if(two>1)pq.push(two-1);
            ans++;
        }
        if(!pq.empty())
        ans+=pq.top();
        return ans;
    }
};