class Solution {
public:
    long long minimumTime(vector<int>& time, int totalTrips) {
        long long start = 1,end = 1e14;
        while(start <= end){
            long long trip = 0,mid = start + (end - start)/2;
            for(int i=0;i<time.size();i++) trip += mid / time[i];
            if(trip < totalTrips) start = mid + 1;
            else end = mid - 1;
        }
        return start;
    }
};