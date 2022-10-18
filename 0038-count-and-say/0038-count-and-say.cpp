class Solution {
public:
    string countAndSay(int n) {
         if(n==1)return "1";
        
        string s = countAndSay(n-1);
        
        // return say s
        string out;
        int i=0, count=1;
        while(i<s.size()){
            while(i+1<s.size() && s[i]==s[i+1]){
                i++; count++;
            }
            out+=to_string(count)+s[i];
            count=1; i++;
        }
        return out;
    }
};