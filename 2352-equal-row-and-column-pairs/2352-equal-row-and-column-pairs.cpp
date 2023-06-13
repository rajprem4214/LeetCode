class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int ans = 0;
        int n = grid.size();
     int g[n][n];
       map<vector<int>,int>m;
        vector<int> v;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                v.push_back(grid[j][i]);
            }
            m[v]++;
            v.clear();
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
            v.push_back(grid[i][j]);
                
            }
          for(auto x:m)
          {
              if(x.first == v)
                  ans+=x.second;
          }
            v.clear();
        }
    return ans;
    }
};