class Solution {
public:
    bool isPossibleToShip(vector<int>&weights,int days,int capacity){
        int currDays = 0;
        int currWeight = 0;

        for(auto it :weights){
            currWeight+=it;

            if(currWeight > capacity){
                ++currDays;
                currWeight = it;

                if(currDays > days)
                return false;
            }
        }

        if(currWeight > 0)
        ++currDays;

        return currDays <= days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int maxCapacity = 0;
        int minCapacity = INT_MIN;

        for(auto it: weights){
            minCapacity = max(minCapacity,it);
            maxCapacity += it;
        }

        //cout<<"Min : "<<minCapacity<<"\t max : "<<maxCapacity<<endl;

        while(minCapacity < maxCapacity){
            int mid = minCapacity + (maxCapacity - minCapacity)/2;

            if(isPossibleToShip(weights,days,mid)){
               // cout<<"It is possible to ship with capacity : "<<mid<<endl;
                maxCapacity = mid;
            }else{
                minCapacity = mid+1;
            }
        }
        return minCapacity;
    }
};