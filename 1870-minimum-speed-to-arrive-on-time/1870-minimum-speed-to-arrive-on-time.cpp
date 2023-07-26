class Solution {
public:
    bool pred(int m, double hour, vector<int>&dist)
    {
       double t=0;
        for(int i=0;i<dist.size();i++)
        {
            double time = (double)dist[i]/m;
            if(i!=dist.size()-1) t+=ceil(time);
            else t+=time;
            
        }
        return t<=hour;
    }
    
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int low=1, high=1e7;
        int ans = -1;
        while(low <= high)
        {
            int m = (low+high)/2;
            if(pred(m, hour, dist))
            {
                ans = m;
                high = m-1;
            }else
                low = m+1;
            
        }
        return ans;
    }
};