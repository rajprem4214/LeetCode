class Solution {
public:
    int strStr(string haystack, string needle) {
                int n=needle.length();
        if(n==0){
            return 0;
        }
        for(int i=0;i<haystack.length();i++){
            if(haystack.substr(i,n)==needle){
                return i;
                break;
            }
        }return -1;

        
    }
};