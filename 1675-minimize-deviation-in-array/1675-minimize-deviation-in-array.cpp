class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        priority_queue<int> pq ;
        int mn = INT_MAX , diff = INT_MAX ;
        for(auto n : nums)
        {
            if(n%2!=0){
                n = n*2 ;
            }
            mn = min(mn,n) ;
            pq.push(n) ;
        }
        while(pq.top()%2==0)
        {
            int top = pq.top() ;
            pq.pop() ;
            diff = min(diff,top-mn) ;
            mn = min(mn,top/2) ;
            pq.push(top/2);
        }
        return min(diff,pq.top()-mn) ;
    }
};
