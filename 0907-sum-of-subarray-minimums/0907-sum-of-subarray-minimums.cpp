class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        stack<int> st;
        long long int ans = 0;
        int mod = 1e9 + 7;
        for(int i=0; i<=arr.size(); i++) {
            while(!st.empty() && (i==arr.size() || arr[st.top()] >= arr[i])) {
                int mid = st.top();
                st.pop();
                int left = st.empty()?-1:st.top();
                long long int temp = arr[mid];
                ans = (ans + (mid-left)*(i-mid)*temp) % mod;
            }
            st.push(i);
        }
        
        return  ans;
    }
};