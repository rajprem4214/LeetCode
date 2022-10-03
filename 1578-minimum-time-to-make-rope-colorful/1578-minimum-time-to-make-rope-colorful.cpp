class Solution {
public:
    int minCost(string s, vector<int>& v) {
        int n=v.size();
        vector<vector<int>> v1;
        for(int i=0;i<n;i++){
            int j=i+1;
            vector<int> x;
            x.push_back(v[i]);
            while(j<n && s[i]==s[j]){
                x.push_back(v[j]);
                j++;
            }
            v1.push_back(x);
            i=j-1;
        }
      
        int ans=0;
        for(int i=0;i<v1.size();i++){
            if(v1[i].size()==1) continue;
            sort(v1[i].begin(),v1[i].end());
            for(int j=0;j<v1[i].size()-1;j++)
                ans+=v1[i][j];
        }
        return ans;
    }
};