class Solution {
public:
    int minimumSum(int num) {
        vector<int>numArr;
        
        while(num > 0) {
            numArr.push_back(num % 10);
            num /= 10;
        }
        
        sort(numArr.begin(), numArr.end());
        
        int first, second;
        
        first = (numArr[0] * 10) + numArr[2];
        second = (numArr[1] * 10) + numArr[3];
        
        return first + second;
    }
};