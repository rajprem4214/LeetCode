class Solution {
public:
    int maxProduct(vector<int>& nums) {
        priority_queue<int> pq;
        for(int i=0;i<nums.size();i++){
            pq.push(nums[i]);
        }
        
        int a = pq.top();
        pq.pop();
        int b = pq.top();
        pq.pop();
    
        return (a-1)*(b-1);
        
    }
};