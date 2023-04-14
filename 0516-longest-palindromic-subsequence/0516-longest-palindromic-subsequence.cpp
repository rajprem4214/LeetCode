class Solution {
public:
    int lcs(string s, string p, int n)
    {
        int t[n+1][n+1];
        //if anyone of the string is of 0 length (i==0||j==0) then lcs will be 0
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=n;j++)
            {
                if(i==0||j==0)
            t[i][j]=0;
            }
        }
        for(int i=1;i<=n;i++)
        {
            //lcs when s string is of size i and p string of length j
            for(int j=1;j<=n;j++)
            {
                //if on both index we encounter same char, we will continue the substring
                if(s[i-1]==p[j-1])
                {
                    t[i][j]=t[i-1][j-1]+1;
                }
                //if we get differnet char, we will find maximum possible lcs with s string first i characters and string p first j characters
                else
                {
                    t[i][j]=max(t[i-1][j],t[i][j-1]);
                }
            }
        }
        // lcs when both string have n charcters
        return t[n][n];
    }
    int longestPalindromeSubseq(string s) {
        int n=s.length();
        string p=s;
        reverse(p.begin(),p.end());
        return lcs(s,p,n);

    }
};