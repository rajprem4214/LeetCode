class Solution {
public:
    string reverseWords(string s) {
   string tmp;
        vector<string> v;
        
        for(auto &i : s)
        {
            if(i != ' ')
                tmp += i;
            else
            {
                if(tmp.size())
                    v.push_back(tmp);
                
                tmp = "";
            }
        }
        
        if(tmp.size())
            v.push_back(tmp), tmp = "";
        
        reverse(v.begin(), v.end());
        for(auto &i : v)
            tmp += (tmp.size() ? " " : "") + i;
        
        return tmp;
    }
};