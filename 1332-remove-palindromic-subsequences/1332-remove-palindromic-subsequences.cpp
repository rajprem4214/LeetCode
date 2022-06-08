class Solution {
public:
    int removePalindromeSub(string s) {
        int i=0, j=s.size()-1;
        while(i<j) {
			//If string is not palindrome return 2
            if(s[i]!=s[j]) return 2;
            i++;
            j--;
        }
        
        return 1;
    }
};