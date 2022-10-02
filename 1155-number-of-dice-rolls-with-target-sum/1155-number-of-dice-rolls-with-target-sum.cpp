#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
class Solution
{
public:
    vector<vector<ll>> dp;
    ll mod = 1e9 + 7;
    ll recur(ll i, ll k, ll targetSum, ll n)
    {
        if (i == n + 1 || targetSum < 0)
            return targetSum == 0 ? 1 : 0;
        if (dp[i][targetSum] != -1)
            return dp[i][targetSum];
        ll ans = 0;
        for (int j = 1; j <= k; j++)
            ans += recur(i + 1, k, targetSum - j, n) % mod;
        return dp[i][targetSum] = ans % mod;
    }
    int numRollsToTarget(int n, int k, int target)
    {
        dp = vector<vector<ll>>(n + 5, vector<ll>(target + 5, -1));
        return recur(1, k, target, n) % mod;
    }
};