class Solution {
public:
    int countTriplets(vector<int>& arr) {
         int ps = 0;
        int len = arr.size();
        int ans = 0;
        for(int i=1 ; i<len ;i++)   arr[i] = arr[i-1]^arr[i];
        for(int i=0 ; i<len ; i++){
            
            for(int k=len-1; k>i ; k--){
                for(int j=k ; j>i ; j--){
                    ans += (arr[j-1]^ps) == ((arr[k]^ps)^(arr[j-1]^ps));
                }
            }
            ps = arr[i];
        }
        return ans;
    }
};