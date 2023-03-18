#define ll long long
class Solution {
public:
    long long repairCars(vector<int>& ranks, int cars) {
         long long lo=0, hi=1e14;
        while( lo<hi ){
            ll mid=(lo+hi)/2;
            ll count=0;
            for(int i=0;i<ranks.size();i++){
                count+=sqrt(mid / ranks[i]);
            }
            if(count>=cars) hi=mid;
            else  lo=mid+1;
        }
        return lo;
    }
};