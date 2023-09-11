class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        map<int,vector<int>> mp;
        vector<vector<int>> ans;
        for(int i=0;i<groupSizes.size();i++){
            mp[groupSizes[i]].push_back(i);
        }
        for(auto i:mp){
            vector<int> temp;
            for(auto j: i.second){
                temp.push_back(j);
                if(temp.size()==i.first){
                    ans.push_back(temp);
                    temp.clear();
                }
            }
        }
        return ans;
    }
};