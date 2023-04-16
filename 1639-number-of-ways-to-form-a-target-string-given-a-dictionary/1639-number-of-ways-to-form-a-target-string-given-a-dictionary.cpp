class Solution {
public:
    int numWays(vector<string>& words, string target) {
        int m=words[0].size();
        int n=target.size();
        int numberOfChars[m+1][26];
        long long ans[m+2][n+2];
        memset(numberOfChars,0,sizeof(numberOfChars));
        memset(ans,0,sizeof(ans));
        long long mod=1e9+7;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<words.size();j++)
            {
                numberOfChars[i][words[j][i]-'a']++;
            }
        }
        
        for(int i=0;i<=m;i++)
        {
            for(int j=0;j<=n;j++)
            {
                if(i==0&&j==0)
                {
                    ans[i][j]=1;
                }
                else if(i==0)
                {
                    ans[i][j]=0;
                }
                else if(j==0)
                {
                    ans[i][j]=1;
                }
                else
                {
                    ans[i][j]=((long long) numberOfChars[i-1][target[j-1]-'a']*ans[i-1][j-1]+ans[i-1][j])%mod;
                }
            }
        }
        return ans[m][n];
    }
};