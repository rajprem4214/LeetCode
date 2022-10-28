class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string,vector<string>>m;
        for(auto &x:strs)
        {
            string t = x;
            sort(x.begin(),x.end());
            m[x].push_back(t);
        }
        vector<vector<string>>ans;
        for(auto x:m)
        {
            ans.push_back(x.second);
        }
        return ans;
    }
};