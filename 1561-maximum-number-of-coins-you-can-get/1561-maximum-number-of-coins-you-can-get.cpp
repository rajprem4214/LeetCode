class Solution {
public:
    int maxCoins(vector<int>& piles) {
        int n = piles.size();
        int k = n/3;
        sort(piles.begin(),piles.end(),greater<int>());
        
        int ans = 0;
        int cnt=1;
        while(k--){
            ans+=piles[cnt];
            cnt+=2;
        }
        return ans;
    }
};