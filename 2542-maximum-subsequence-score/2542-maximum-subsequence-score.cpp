class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<pair<int,int>> arr;
        int n = nums1.size();
        for(int i=0; i<n; i++){
            arr.push_back({nums2[i], nums1[i]});
        }
        sort(arr.rbegin(), arr.rend());
        priority_queue<int, vector<int>, greater<int>> minHeap;
        long long top_K_sum = 0;
        long long res = 0;
        for(auto &[minValue, comp]:arr){
            //see if minHeap meets the maximum
            if(minHeap.size()==k){
                top_K_sum-= minHeap.top();
                minHeap.pop();
            }
            top_K_sum+=comp;
            minHeap.push(comp);
            if(minHeap.size()==k){
                long long curr = (long long)top_K_sum * minValue;
                res = max(res , curr);
            }
        }
        return res;
    }
};