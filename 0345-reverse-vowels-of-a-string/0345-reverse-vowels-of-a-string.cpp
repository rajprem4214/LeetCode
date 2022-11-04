class Solution {
public:
    bool isVowel(char c) const{
        return c=='a' || c=='e' || c=='i' || c=='o' || c=='u' || 
            c=='A' || c=='E' || c=='I' || c=='O' || c=='U';
    }
    string reverseVowels(string s) {
        int i=0;
        int j=s.length()-1;
        while(i<j){
            if(isVowel(s[i]) && isVowel(s[j])){
                swap(s[i],s[j]);
                i++;
                j--;
            }
            else if(isVowel(s[i])&&!isVowel(s[j])){
                j--;
            }
            else if(!isVowel(s[i])&&isVowel(s[j])){
                i++;
            }
            else{
                i++;
                j--;
            }
        }
        return s;
    }
};