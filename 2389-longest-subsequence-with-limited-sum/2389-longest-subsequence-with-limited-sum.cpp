class Solution {
public:

    int floor(vector<int> &sum,int value){
        int low=0,high=sum.size()-1;
        int ans=0;
        while(low<=high){
            int mid=(low+high)/2;
            if(sum[mid]<=value){
                ans=mid+1;
                low=mid+1;
            }else{
                high=mid-1;
            }
        }
        return ans;
    }
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {

        vector<int> sum(nums.size(),0),ans(queries.size());

        sort(nums.begin(),nums.end());
        
        sum[0]=nums[0];
        for(int i=1;i<nums.size();i++){
            sum[i]=sum[i-1]+nums[i];
        }

        for(int i=0;i<queries.size();i++){
            ans[i]=floor(sum,queries[i]);
        }

        return ans;

    }
};