typedef int ll;
class Solution {
public:
    ll dp[105][105];
 
    ll get(ll x1,ll y1,ll x2,ll y2){
        return dp[x2+1][y2+1] - dp[x1][y2+1] - dp[x2+1][y1] + dp[x1][y1];
    }
    int maxSumSubmatrix(vector<vector<int>>& arr, int ch) {
        ll n = arr.size(),m = arr[0].size();
        for(ll i = 0;i <= n;i++){
            for(ll j = 0;j <= m;j++){
                dp[i][j] = 0;
            }
        }
        for(ll i = 1;i <= n;i++){
            for(ll j = 1;j <= m;j++){
                dp[i][j] = arr[i-1][j-1] + dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1];
            }
        }
        ll ans = -INT_MAX;
        for(ll i = 0;i < n;i++){
            for(ll j = 0;j < m;j++){
                for(ll k = i;k < n;k++){
                    for(ll l = j;l < m;l++){
                        
                        ll temp = get(i, j, k, l);
                        if(temp > ans && temp <= ch)
                            ans = temp;
                    }
                }
            }
        }
        return ans;
    }
};