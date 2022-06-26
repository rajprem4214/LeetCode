class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        long long sum = accumulate(cardPoints.begin(), cardPoints.end(), 0LL);
        
        int ans = 0;
        int n = cardPoints.size();
        int windowSize = n - k;
        int L = 0;
        int R = 0;
        long long windowSum = 0;
        
        while(R < n) {
            int right = cardPoints[R++];
            windowSum += right;
            while(R - L > windowSize) {
                int left = cardPoints[L++];
                windowSum -= left;
            }
            if(R-L == windowSize) {
                ans = max(ans, (int)(sum - windowSum));
            }
        }
        return ans;
    }
};