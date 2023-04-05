class Solution {
public:
    int minimizeArrayValue(vector<int>& nums) {
            int l=0,h=*max_element(nums.begin(),nums.end());
        int n=nums.size();
        while(l<h){
            int m=(l+h)/2;
            int fl=0;
            long long cnt=0;
            for(int i=0;i<n;i++){
                if(nums[i]<=m) cnt+=(m-nums[i]);
                else{
                    if(cnt<(nums[i]-m)) {
                        fl=1;
                        break;
                    }
                    else cnt-=nums[i]-m;
                }
            }
           
             if(fl==1) l=m+1;
            else  h=m;
        }
        
        return l;
    }
};