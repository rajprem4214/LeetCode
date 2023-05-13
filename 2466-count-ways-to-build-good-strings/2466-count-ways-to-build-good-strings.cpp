class Solution {
vector<int>dp;
int mod=1000000007;
public:
    int counttotalNumberofString(int len,int zero,int ones){
        if(len==0){
            return 1;
        }
        if(len<0) return 0;
        if(dp[len]!=-1) return dp[len];

        int result=(counttotalNumberofString(len-zero,zero,ones)+counttotalNumberofString(len-ones,zero,ones))%mod;
        return dp[len]=result;
    }
    int countGoodStrings(int low, int high, int zero, int one) {
        dp.clear();
        dp.resize(high+1,-1);
        long long int result=0;

        for(int len=low;len<=high;len++){
            result=(result+counttotalNumberofString(len,zero,one))%mod;
        }
        return static_cast<int>(result);
    }
};