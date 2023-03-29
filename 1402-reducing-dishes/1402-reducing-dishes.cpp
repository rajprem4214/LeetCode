class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        vector<int>t=satisfaction;
        sort(t.begin(),t.end());
        reverse(t.begin(),t.end());
        int sum=0,ans=0;
        for(int i=0;i<t.size();i++){
            if(sum+t[i]>0){
                ans+=sum+t[i];
                sum+=t[i];
            }
        }
        return ans;
    }
};