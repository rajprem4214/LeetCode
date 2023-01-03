class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        
        int n = strs.size();
        int m = strs[0].size();
        int ans = 0; 

        for(int j = 0; j < m; j++)
        {
            for(int i = 0; i < n-1; i++)
            {
                // cout<<i<<" "<<j<<" "<<strs[i][j]<<" || "<<i+1<<" "<<j<<" "<<strs[i+1][j]<<endl;
                if(strs[i][j] > strs[i+1][j])
                {
                    ans++;
                    break;
                }
                else
                {
                    continue;
                }
            }
        }

        return ans;
    }
};