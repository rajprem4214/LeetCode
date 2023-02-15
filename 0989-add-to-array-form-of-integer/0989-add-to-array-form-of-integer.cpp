class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        int carry = 0;
        for(auto it = num.rbegin(); it!= num.rend(); it++){
            *it += (k%10) + carry;
            if(*it > 9){
                carry = *it / 10;
                *it %= 10;
            }
            else carry = 0;
            k /= 10;
        }
        carry += k;
        if(carry){
            while(carry){
                num.insert(num.begin(), carry % 10);
                carry /= 10;
            }
        }
        return num;
    }
};