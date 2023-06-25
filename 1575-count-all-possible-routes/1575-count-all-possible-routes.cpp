class Solution {
public:
    int dp[105][205];
    int mod= 1000000007;
    int visitCity(int city, int fuel, vector<int>& locations, int finish, int n)
    {
        if(fuel<0) return 0;
        if(dp[city][fuel]!=-1)
        return dp[city][fuel];
        int count=0;
        
        if(city==finish)
        count ++;
        for(int i=0; i<n;i++)
        {
            if(i!=city)
            {
                int fuelUsed= locations[i]>locations[city]?locations[i] -locations[city]: locations[city]-locations[i];
                count+= visitCity(i, fuel-fuelUsed, locations, finish, n);
                count%= mod;
            }
        }
        return dp[city][fuel]= count%mod;
        
    }
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) 
    {
        int n= locations.size();
        memset(dp, -1, sizeof(dp));
        int count =visitCity(start, fuel, locations, finish, n);
        return count;
    }
};