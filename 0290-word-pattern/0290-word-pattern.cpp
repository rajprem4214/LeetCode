class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string> words;
        string temp = "";
        for(int i=0; i<s.length(); i++) {
            if(s[i]==' ') {
                words.push_back(temp);
                temp = "";
            } else {
                temp+=s[i];
            }
        }
        words.push_back(temp);

        int n = pattern.length();
        int m = words.size();
        if(n!=m) return false;
        unordered_map<char, string> mp;
        unordered_map<string, int> taken;
        for(int i=0; i<n; i++) {
            if(mp.find(pattern[i])!=mp.end()) {
                if(words[i]!=mp[pattern[i]]) return false;
            } else {
                if(taken.find(words[i])!=taken.end()) return false;
                mp[pattern[i]]=words[i];
                taken[words[i]]=1;
            }
        }
        return true;
    }
};