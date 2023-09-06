class Solution {
public:
    int numberOfSubstrings(string s) {
        int ans = 0;
        map<char, int> mp;
       int i =0, j = 0;
        while(j < s.size())
        {
            mp[s[j]]++;
            while(mp.size() == 3)
            {
                ans += s.size() - j;
                mp[s[i]]--;
                if(mp[s[i]] == 0)
                    mp.erase(s[i]);
                i++;
            }
            j++;
        }
        
        return ans;
    }
};