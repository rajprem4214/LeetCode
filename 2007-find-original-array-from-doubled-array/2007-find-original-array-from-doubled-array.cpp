class Solution {
public:
    vector<int> findOriginalArray(vector<int>& c) {
        sort(c.begin(),c.end());
        map<int,int> m;
        for(auto x:c)
        {
            m[x]++;
        }
        vector<int> ans;
        for(int i=0;i<c.size();i++)
        {
            if(m[c[i]]==0) continue;
            if(m[2*c[i]]==0) return {};
        if(m.find(c[i]*2)!=m.end() && m[c[i]]>0)
            {
                ans.push_back(c[i]);
                m[c[i]*2]--;
                 m[c[i]]--;
            }
        }
        // cout<<m[2];
        // cout<<ans.size();
        if(ans.size() != c.size()/2)
            return {};
        else
            return ans;
        
    }
};