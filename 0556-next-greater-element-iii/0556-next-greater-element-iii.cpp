class Solution {
public:
    int nextGreaterElement(int n) {
       vector<int>digits;
        int number=n;
        while(number){
            digits.push_back(number%10);
            number/=10;
        }
        reverse(digits.begin(),digits.end());
        next_permutation(digits.begin(),digits.end());
        long ans=0;
        for(int i=0;i<digits.size();i++){
            ans*=10;
            ans+=digits[i];
        }
        if(ans>(long)INT_MAX or ans<=n){
            return -1;
        } else {
            return (int)ans;
        }
        
    }
};