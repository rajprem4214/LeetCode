class Solution {
public:
    int maxValue(int n, int index, int maxSum) {
        int left = index;
        int right = index;
        maxSum -=n;
        int ans = 1;
        while(maxSum>= (right-left+1)){
            maxSum -= (right-left+1);
            ans++;
            if(left >0)
            left--;
            if(right<n-1)
            right++;
            if(n==(right-left+1))
            break;
        }
        ans +=maxSum/n;
        return ans;
    }
};