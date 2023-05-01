class Solution {
public:
    double average(vector<int>& s) {
        sort(s.begin(), s.end());
        double ans =0;
        int n = s.size();
        for(int i=1; i<n-1;i++){
            ans +=s[i];
        }
        ans = ans/(n-2);
        return ans;
    }
};