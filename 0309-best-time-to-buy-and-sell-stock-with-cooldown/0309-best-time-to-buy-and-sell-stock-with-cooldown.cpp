class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n= prices.size();
        vector<vector<int>> v(n, vector<int>(2,-1));

        function<int(int, bool)> dfs=[&](int i, bool x){
            if(i>=n) return 0;
            if(v[i][x]!=-1) return v[i][x];
            int trans, cooldown;
            cooldown= dfs(i+1,x);
            if(x) trans = dfs(i+1,!x)-prices[i];
            else trans = dfs(i+2, !x)+prices[i];
            return v[i][x]= max(trans, cooldown);
        };
        return dfs(0,1);
    }
};