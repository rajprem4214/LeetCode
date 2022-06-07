class Comp {
    public:
    bool operator ()(pair<int, int> &a, pair<int, int> &b) {
        return a.first < b.first;
}    
};

class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        vector<string> ans(score.size(), "0");
        priority_queue<pair<int, int>, vector<pair<int, int>>, Comp> pq;
        for(int i = 0; i < score.size(); i++) {
            pq.push({score[i], i});
        }
        for(int i = 1; i <= score.size(); i++) {
            if(i == 1)
                ans[pq.top().second] = "Gold Medal";
            else if(i == 2)
                ans[pq.top().second] = "Silver Medal";
            else if(i == 3)
                ans[pq.top().second] = "Bronze Medal";
            else {
                ans[pq.top().second] = to_string(i); 
            }
            pq.pop();
        }
        return ans;
    }
};