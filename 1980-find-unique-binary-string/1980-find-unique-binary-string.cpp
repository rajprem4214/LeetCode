class Solution {
public:
    string sup;
    bool flg= false;
    void recursion(int index ,int size,string s,map<string,int>mpp){
        if(flg) return;
        if(s.size()==size){
            if(mpp[s]==0) {
                sup=s;
                flg=true;
                return;
            }
            return;
        }
        if(index>size) return;
        recursion(index+1,size,s+'0',mpp);
        recursion(index+1,size,s+'1',mpp);
        
    }
    string findDifferentBinaryString(vector<string>& nums) {
        int size = nums.size();
        string s="";
        map<string,int>mpp;
        for(auto it: nums){
            mpp[it]+=1;
        }
        recursion(0,nums[0].size(),s,mpp);
        return sup;
    }
};