class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
     set<string>s;
        string code[26] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        // return code[0].length();
        for(auto a:words){
            string st = a;
            string str;
            for(int i=0;i<st.length();i++){
                int x = st[i]-97;
                str+=code[x];
            }
            s.insert(str);
        }
        return s.size();
    }
};