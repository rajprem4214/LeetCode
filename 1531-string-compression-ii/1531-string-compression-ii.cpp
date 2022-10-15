int dp[101][27][101][101]; // ind last len k
class Solution
{
public:
	int getLengthOfOptimalCompression(string s, int k)
	{

		memset(dp, -1, sizeof(dp));

		function<int(int, int, int, int)> solve = [&](int ind, int last, int len, int k)
		{
			// base case
			if (k < 0)
				return 100;
			if (ind >= s.size())
				return 0;

			// dp
			int &ans = dp[ind][last][len][k];
			if (ans != -1)
			{
				return ans;
			}

			if (last == s[ind] - 'a')
			{
				int carry = (len == 1 || len == 9 || len == 99); // AFTER ADD : if len = 2 -> a2 ||  if len = 10 -> a10 || if len = 100 -> a100
				ans = carry + solve(ind + 1, last, len + 1, k);
			}
			else
			{
				// int call_1 =           // delete s[ind]
				// int call_2 =        // keep s[ind]
				ans = min(solve(ind + 1, last, len, k - 1), 1 + solve(ind + 1, s[ind] - 'a', 1, k));
			}
			return ans;
		};
		return solve(0, 26, 0, k);
	}
};