#define ll long long
class Solution {
public:
    ll mod = 1000000007;
    ll dp[11][51][51];
    
    bool check(vector<string>& pizza, int rs, int re, int cs, int ce){ 
        for(int i=rs; i<=re; ++i){
            for(int j=cs; j<=ce; ++j){
                if(pizza[i][j] == 'A') return true;
            }
        } 
        return false;
    }
    
    ll solve(vector<string>& pizza, int k, int rs, int cs){
        int n = pizza.size(), m=pizza[0].size();
        if(k<=0) return 1;
        if(dp[k][rs][cs] != -1) return dp[k][rs][cs];
        
        ll count = 0;
        for(int i=rs; i<n-1; ++i){
            if(check(pizza, rs, i, cs, m-1) && check(pizza, i+1, n-1, cs, m-1)){
               count = (count%mod + solve(pizza, k-1, i+1, cs)%mod)%mod;
            }
        }
        
        for(int j=cs; j<m-1; ++j){
            if(check(pizza, rs, n-1, cs, j) && check(pizza, rs, n-1, j+1, m-1)){
                count = (count%mod + solve(pizza, k-1, rs, j+1)%mod)%mod;
            }
        }
        
        return dp[k][rs][cs] = count%mod;
    }
    
    int ways(vector<string>& pizza, int k) {
        int n = pizza.size(), m = pizza[0].size();
        memset(dp, -1, sizeof(dp));
        return solve(pizza, k-1, 0, 0);
    }
};