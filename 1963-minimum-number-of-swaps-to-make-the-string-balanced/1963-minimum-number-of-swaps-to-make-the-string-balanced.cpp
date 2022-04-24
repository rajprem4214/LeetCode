class Solution {
public:
    int minSwaps(string s) {
        int i = 0;
        int j = s.length()-1;
        int closeCount = 0;
        int openCount = 0;
        int totalSwap = 0;
        while(i < j) {
            if(s[i] == '[') {
                openCount++;
            }
            else {
                closeCount++;
            }
            // if close count is greater than opencount
            // we need to swap it with end open bracket
            if(closeCount > openCount) {
                while(s[j] != '[') {
                    j--;
                }
                // after swapping increase openCount, reduce close count and update total count
                swap(s[i], s[j]);
                openCount++;
                closeCount--;
                totalSwap++;
            }
            i++;
        }
        return totalSwap;
    }
};