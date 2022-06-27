class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n = arr.size();
        vector<int> ans(queries.size()),pre(n);
         pre[0] = arr[0];
        
        for(int  i=1;i<arr.size();i++){
            pre[i] = (pre[i-1]^arr[i]);
        }
        
        for(int i=0;i<queries.size();i++){
            if(queries[i][0])
                ans[i] = pre[queries[i][1]]^pre[queries[i][0]-1];
            else
                ans[i] = pre[queries[i][1]];
        }
        
        return ans;
    }
};