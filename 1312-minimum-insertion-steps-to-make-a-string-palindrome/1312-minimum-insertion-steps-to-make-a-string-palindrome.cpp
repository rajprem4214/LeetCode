int dp[505][505];
class Solution {
public:
  int call(string &s, int i, int j){
		if(i >= j) return 0;
		if(dp[i][j] != -1) return dp[i][j];
		int ret = INT_MAX;
		if(s[i] != s[j]){
			ret = min({ret, 1+call(s, i+1, j), 1+call(s, i, j-1), 2+call(s, i+1, j-1)});
		}
		else{
			ret = min(ret, call(s, i+1, j-1));
		}
		return dp[i][j]=ret;
	}

	int minInsertions(string s) {
		memset(dp, -1, sizeof(dp));
        return call(s, 0, s.size()-1);
    }
};