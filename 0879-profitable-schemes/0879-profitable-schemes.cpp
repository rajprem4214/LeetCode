class Solution {
public:
    int N;
    int dp[101][101][101];
    const int MOD = 1e9 + 7;
    int solve(int index, int total_profit, int total_group, int &minProfit,vector<int>& group, vector<int>& profit)
    {
        if(total_group>N)
        {
            return 0;
        }


        if(index == group.size())
        {
            if(total_profit >= minProfit)
            {
                return 1;
            }

            else{
                return 0;
            }
        }

        if(dp[index][total_profit][total_group]!=-1)
        {
            return dp[index][total_profit][total_group];
        }


        long long not_take = solve(index + 1, total_profit,total_group,minProfit, group, profit)%MOD;
        
        //  min(total_profit + profit[index], minProfit) is used for Memoization purpose.

        long long take = solve(index + 1, min(total_profit + profit[index], minProfit),total_group + group[index],minProfit, group, profit)%MOD;


        return  dp[index][total_profit][total_group] = (not_take%MOD + take%MOD)%MOD;
    }
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {

        N = n;

        memset(dp, -1, sizeof(dp));

        return solve(0,0,0,minProfit, group, profit);
        
    }
};