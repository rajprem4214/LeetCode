class Solution {
public:
    int solve(int n,vector<int> &dp,vector<int>& days,vector<int>& costs,int i){
        if(i>=n) return 0;
        if(dp[i]!=-1) return dp[i];
        int opt1= costs[0]+solve(n,dp,days,costs,i+1);
        int k=0;
        for(k=i;k<n && days[k]<days[i]+7;k++);
        int opt2=costs[1]+solve(n,dp,days,costs,k);
        k=0;
        for(k=i;k<n && days[k]<days[i]+30;k++);
        int opt3=costs[2]+solve(n,dp,days,costs,k);
        return dp[i]=min(opt1,min(opt2,opt3));
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        vector<int> dp(n+1, -1);
        return solve(n,dp,days,costs,0);
    }
};