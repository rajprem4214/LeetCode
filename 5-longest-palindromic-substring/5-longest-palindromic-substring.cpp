class Solution {
public:
	string longestPalindrome(string s) {
		int n=s.size(),start=0,maxLen=1;
		if(!n)  return "";
		int dp[n][n];
		memset(dp,-1,sizeof dp);
		for(int i=0;i<n;i++)    dp[i][i] = 1;
		for(int i=0;i<n-1;i++)
			if(s[i]==s[i+1])
			{
				dp[i][i+1] = 1;
				start = i;
				maxLen = 2;
			}
		for(int k=3;k<=n;k++){
			for(int i=0;i<n - k + 1;i++){
				int j = i + k - 1;
				if(dp[i+1][j-1]==1 && s[i]==s[j]){
					dp[i][j] = 1;
					if (k > maxLen) {
						start = i; 
						maxLen = k; 
					} 
				}
			}
		}
		return s.substr(start, maxLen);
	}
};