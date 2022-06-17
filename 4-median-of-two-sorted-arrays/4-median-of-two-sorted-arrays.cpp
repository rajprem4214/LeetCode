class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        int l1 = nums1.size();
        int l2 = nums2.size();
        int i =  0;
        int j = 0;
        int f[l1+l2];
        int k =0;
        while(i<l1 && j<l2){
            if(nums1[i] < nums2[j])
            {
                f[k++] = nums1[i++];
                
            }
            else 
            {
               f[k++] = nums2[j++];
                
            }
            
            
        }
        while(i<l1)
        {
            f[k++] = nums1[i++];
            
        }
        
        while(j<l2){
            f[k++] = nums2[j++];
            
        }
        double ans = 0.0;
            int mid = (l1+l2)/2;
        if((nums1.size()+nums2.size()) % 2 ==0)
        {
            
            
            ans =(f[mid-1] + f[mid])/2.0;
        } 
        else
        {
         //   int mid = (l1+l2)/2;
            ans = f[mid];
        }
        
        return ans;
        
    }
};