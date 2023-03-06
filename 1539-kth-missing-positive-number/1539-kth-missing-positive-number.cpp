class Solution {
public:
    int compute(int actual , int expected){
        return actual - expected;
    }
    
    int findKthPositive(vector<int>& arr, int k) {
        int size = arr.size();
        int start = 0 , end = size-1;
        int missingNums = compute(arr[size-1],size);
        
        while(start<=end){
            int mid = start + (end-start)/2;
            missingNums = compute(arr[mid],mid+1) ;
            if(missingNums>= k){
                end = mid-1;
            }
            else start = mid+1;
            
        }
        if(end == -1) return k;
        return arr[end] + k-compute(arr[end],end+1);
        
    }
};