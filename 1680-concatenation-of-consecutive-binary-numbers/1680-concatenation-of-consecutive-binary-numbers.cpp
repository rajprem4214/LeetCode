class Solution {
public:
    int m=1e9+7;
    int concatenatedBinary(int n) {
        int bit=0;
        long ans=0;
        for(int i=1;i<=n;i++){
            if((i&(i-1))==0)bit++;
            ans= ((ans << bit) % m + i) % m;
        }
        return ans;
    }
};