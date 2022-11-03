class Solution {
public:
    string convertToBase7(int num) {
      
        int rem, ans = 0, i = 0;
        
        while( num!= 0){
            rem = num % 7; // reminder after dividing by 7
            ans += rem * pow(10, i);
            i++;
            num = num/7;
        }
        
        return to_string(ans);    
    }
};