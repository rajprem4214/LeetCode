class Solution {
public:
    bool isPossible(vector<int> &arr,int val,int h){
        int i;
        for(i=0;i<arr.size();++i){
            int x=ceil((arr[i]*1.0)/val);
            h-=x;
        }
        return h>=0;//if we have exhausted all hours,then it is not
                    //possible to eat all bananas with val speed
    }
    int maxEle(vector<int> &arr){
        int i,maxi=arr[0];
        for(i=1;i<arr.size();++i)
            maxi=max(maxi,arr[i]);
        return maxi;
    }
    int minEatingSpeed(vector<int>& arr, int h) {
        //another book allocation variation
        int f=1,l=maxEle(arr),ans=l;
        while(f<=l){
            int mid=f+((l-f)>>1);
            if(isPossible(arr,mid,h)){
                ans=mid;
                l=mid-1;
            }
            else    f=mid+1;
        }
        return ans;
    }
};