class Solution {
private:
const int mod = 1e9+7;
int DP[100001];

int f(int ind, string &s, int k) {

    if(ind == s.length()) return 1;

    if(s[ind] == '0') return 0;

    if(DP[ind] != -1) return DP[ind];

    long long num = 0;
    int ans = 0;
    for(int i=ind; i<s.length(); i++) {

        num = (num * 10) + s[i] - '0';
        if(num > k) break;
        ans = (ans % mod + f(i+1, s, k) % mod) % mod;
    }

    return DP[ind] = ans;
}
public:
    int numberOfArrays(string s, int k) {
    memset(DP, -1, sizeof(DP));
    return f(0, s, k);       
    }
};