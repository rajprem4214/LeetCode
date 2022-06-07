class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
		//Size of nums1 including 0's
        int k=m+n-1;
		
		//Both the pointers to point at last index
        m--;
        n--;
		
        while(m>=0 && n>=0) {
			//Comparing the values and adjusting the k value accordingly
            if(nums1[m]>nums2[n]) nums1[k--]=nums1[m--];
            else nums1[k--]=nums2[n--];
        }
		
		//It might happen that elements of second array are smaller than smallest element of first array
        while(n>=0) nums1[k--]=nums2[n--];
		
		//We need not cover the otherwise case of first array elements begin smaller, because they are already in first half of the array
    }
};