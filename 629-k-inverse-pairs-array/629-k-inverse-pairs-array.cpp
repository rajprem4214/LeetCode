class Solution {
public:
    int kInversePairs(int n, int k) {
        vector<int> pre(k + 1);
        pre[0] = 1;
        vector<int> cur(k + 1);
        int mod = 1e9 + 7;
        for (int i = 2; i <= n; i++) {
            int sum = 0;
            for (int j = 0; j <= k; j++) {
                sum += pre[j];
                if (j - i >= 0)
                    sum -= pre[j - i];
                if (sum < 0)
                    sum += mod;
                else
                    sum %= mod;
                //cout<<sum<<" ";
                cur[j] = sum;
            }
            //cout<<endl;
            pre = cur;
        }
        return pre[k];
    }
};