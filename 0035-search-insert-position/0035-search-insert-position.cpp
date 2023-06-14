class Solution {
public:
    int searchInsert(vector<int>& arr, int k) {
        // Brute Force - Linearly traverse over the array and search for target & a number just greater than target.
        
        // Optimal - Use Binary Search 
        
       int n = arr.size();
    int start = 0;
    int end = n-1;
    int res = -1;
    
    while(start<=end){
        
        int mid = start + (end-start)/2 ;
        
        if(arr[mid]==k) return mid;
        
        else if(arr[mid]<k){
            res = mid;
            start = mid+1;
        }
        else end = mid-1;
    }
    return res+1;
        
    }
};