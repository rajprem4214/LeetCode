class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        int n=nums.size();
        typedef long long ll;
        vector<ll>pre(n),suf(n);
        pre[0]=nums[0];
        for(int i=1;i<n;++i)pre[i]=pre[i-1]+nums[i];
        for(int i=n-2;~i;--i)suf[i]=suf[i+1]+nums[i+1];
        int pos=0;
        ll ret=LLONG_MAX;
        for(int i=0;i<n;++i){
            ll tmp=abs(pre[i]/(i+1)-(i+1==n?0:suf[i]/(n-i-1)));
            if(tmp<ret)ret=tmp,pos=i;
        }
        return pos;
    }
};