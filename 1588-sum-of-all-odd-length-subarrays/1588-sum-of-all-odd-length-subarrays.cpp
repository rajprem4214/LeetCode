class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
       int ans=0;
         
        for(int i=0;i<arr.size();i++){
            int curr=0;
            for(int j=i;j<arr.size();j++){
                curr += arr[j];
                 
                if((i&1) == (j&1))
                    ans+=curr;
                
            }
            
        }
        
        return ans;
    }
};