class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
         int temp=0;
        
        // XOR of all elements
        for(auto it:nums) temp^=it;
        
        // get right most set bit
        int firstSet=0;
       
        while(temp){
            if(temp & 1){
                break;
            }
            temp=temp>>1;
            firstSet++;
        }
 
        // as temp is XOR of all which is XOR of (ans1^ans2) as rest of them occure twice and became zero
        // (1^1=0) and (1^0=1) 
        // if ith bit is set in the XOR of both which means ith bit of one is 1 and 0 of another
        // with this we can divide numbers in groups, with ith bit set and unset
        // now we can just xor both groups separately
        int set=0,unset=0;
        for(auto it:nums){
            
            if(it>>firstSet & 1){
                set^=it;
            }else{
                unset^=it;
            }
        }
        
        return {set,unset};
    }
};