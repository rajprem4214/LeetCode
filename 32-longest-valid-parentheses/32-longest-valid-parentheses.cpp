class Solution {
public:
    int longestValidParentheses(string s) {
         stack <pair<char,int>> st;
        st.push({'1', -1}); // Just pushing dummy value
        int maxLen = 0;
        for(int i=0; i<s.size(); i++) {
            if(st.top().first != '(' && s[i] == ')') {
                st.push({s[i], i});
            }
            else if(st.top().first == '(' && s[i] == ')') {
                st.pop();
                maxLen = max(maxLen, i - st.top().second);
            }
            else if(s[i] == '(') {
                st.push({s[i], i});
            }
        }
        return maxLen;
    }
};