class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
         set<int>s;
        map<int,int>lost;
        vector<vector<int>>ans;
        
        for(auto i: matches) {
            s.insert(i[0]);
            s.insert(i[1]);
            lost[i[1]] += 1;
        }
        vector<int>temp;
        for(auto i: s){
            if(lost.find(i)==lost.end()) temp.push_back(i);
        }
        
        ans.push_back(temp);
        temp.clear();
        
        for(auto i:lost){
            if(i.second == 1) temp.push_back(i.first);
        }
        
        ans.push_back(temp);
        
        return ans;
    }
};