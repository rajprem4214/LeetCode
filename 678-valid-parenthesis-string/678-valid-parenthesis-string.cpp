class Solution {
public:
    bool checkValidString(string s) {
         if(s.size() < 2) return (s[0] == '*');
        int closed = 0;
        int open = 0;
        int either = 0;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '(') open++;
            else if(s[i] == ')') closed++;
            else either++;
            if(closed > (open+either)) return false;
        }
        closed = 0;
        open = 0;
        either = 0;
        for(int i = s.size()-1; i >= 0; i--){
            if(s[i] == '(') open++;
            else if(s[i] == ')') closed++;
            else either++;
            if(open > (closed+either)) return false;
        }
        return true; 
    }
};