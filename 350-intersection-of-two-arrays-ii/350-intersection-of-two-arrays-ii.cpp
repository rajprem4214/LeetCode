class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int>ans;
        int arr[1001]={0};
        
        for(int i:nums1){
            arr[i]++;
        }
        
        for(int i:nums2){
            if(arr[i]>0){
                ans.push_back(i);
                arr[i]--;
            }
        }
        
        return ans;
    }
};