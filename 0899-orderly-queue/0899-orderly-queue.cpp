class Solution {
public:
    string orderlyQueue(string s, int k) {
        if(k > 1)
        {
            sort(s.begin(), s.end());
            return s;
        }
        
        string ans = s;
        int n = s.size();
        
        for(int i = 0; i < n; i++)
        {
            s = s.substr(1) + s[0];
            if(ans > s)
                ans = s;
        }
            
        return ans;
    }
};