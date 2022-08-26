class Solution {
public:
    bool reorderedPowerOf2(int n) {
          
        //Convert the integer to string
        string s=to_string(n);
        
        //Sort the string
        sort(s.begin(),s.end());
        
        //Now check for all power till 32 and covert all power into string and sort them
        //If we get any power of 2 string equal to s then return true
        for(int i=0;i<32;i++){
            int power_2=(1<<i);
            string compare=to_string(power_2);
            sort(compare.begin(),compare.end());
            if(compare==s)return true;
        }
        
        return false;
    }
};