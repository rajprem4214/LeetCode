class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int ans = 0;
        
        for(int i=0;i<n;i++)
        {
            int l = 0, h = m-1;
            while(l<=h)
            {
                int mid = l + (h-l)/2;
                if(grid[i][mid] >= 0)
                {
                    l = mid+1;
                }else
                    h = mid - 1;
            }
            ans += (m-l);
        }
        
        return ans;
    }
};