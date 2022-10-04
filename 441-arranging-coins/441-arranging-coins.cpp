#define ll long long
class Solution {
public:
    int arrangeCoins(int n) {
       ll int l = 1, h = 1e7;
       ll int ans = -1;
        while(l<=h)
        {
           ll int m = (l+h)/2;
            if(m*(m+1)/2 <= n)
            {
                ans=m;
                l=m+1;
            }
            else
                h=m-1;
        }
        return ans;
    }
};