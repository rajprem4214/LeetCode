class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        int n = names.size();
        vector<pair<string,int>> v(n);
        for(int i=0;i<n;i++)
        {
            v[i].first = names[i];
            v[i].second = heights[i];
        }
        sort(v.begin(),v.end(),[](pair<string,int>&a, pair<string,int>&b){
            if(a.second>b.second)
                return true;
            else
                return false;
        });
            
            vector<string> ans;
        for(auto x:v)
            ans.push_back(x.first);
    
    return ans;
    }
};