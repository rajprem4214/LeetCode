class Solution {
public:
    vector<string> patterns;
    void getPatterns(int open, int close, int n, string s){
        
        if(open == close and open == n){
            patterns.push_back(s);
            return;
        }
        
        if(open == n){
            getPatterns(open, close+1, n, s + ")");
        }
        else if(open == close){
            getPatterns(open+1, close, n, s + "(");
        }
        else if(open > close){
            getPatterns(open+1, close, n, s + "(");
            getPatterns(open, close+1, n, s + ")");
        }
        
        return;
    }
    
    vector<string> generateParenthesis(int n) {
        patterns.clear();
        string s = "";
        
        getPatterns(0, 0, n, s);
        return patterns;
    }
};