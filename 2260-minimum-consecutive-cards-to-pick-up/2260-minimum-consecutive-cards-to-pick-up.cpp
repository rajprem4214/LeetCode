class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        
        int n = cards.size();
        bool found = false;
        unordered_map<int, int> dp;
        
        dp[cards[0]] = 0;
        
        int ans = INT_MAX;
        
        for(int i = 1 ; i < n ; i++){
            
            if(dp.find(cards[i]) != dp.end()){
                
                ans = min(ans, i - dp[cards[i]] + 1);
                found = true;
                
            }
            
            dp[cards[i]] = i;
            
        }
        
        if(!found) ans = -1;
        return ans;
        
    }
};