class Solution {
public:
    int countPrefixes(vector<string>& words, string s) {
        vector<string> sub;
        int n = s.length();
        for(int i=1;i<=n;i++){
            string x = s.substr(0,i);
            sub.push_back(x);
        }
        
        unordered_map<string,int> m;
        for(int i=0;i<words.size();i++){
            m[words[i]]++;
        }
        int ans=0;
        for(int i=0;i<sub.size();i++){
            
            
            if(m.find(sub[i]) != m.end())
            {
                auto it=m.find(sub[i]);
                ans+=it->second;
            }
            }
        
        return ans;
    }
};