class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int m = 0;
        for(auto c:candies){
            m = max(m, c);
        }

        vector<bool> result;
        for(auto c:candies){
            bool ans = false;
            if(c + extraCandies >= m) ans = true;
            
            result.push_back(ans);
        }

        return result;
    }
};