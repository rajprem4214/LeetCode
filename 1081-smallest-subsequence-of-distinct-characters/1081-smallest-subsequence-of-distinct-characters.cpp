class Solution {
public:
    string smallestSubsequence(string s) {
        stack<char> st;
        int n = s.size();
        map<char,int> exist;
        map<char, int> freq;
        for(int i=0;i<n;i++)
        {
            freq[s[i]]++;
        }
        
        for(int i=0;i<n;i++)
        {
            char ch = s[i];
            if(exist[ch] == 1)
            {
                freq[ch]--;
                continue;
            }
            
            while(!st.empty() && st.top() > ch && freq[st.top()] > 0)
            {
                exist[st.top()] = 0;
                st.pop();
            }
            
            st.push(ch);
            exist[ch] = 1;
            freq[ch]--;
        }
        string ans = "";
        while(!st.empty())
        {
            ans=st.top()+ans;
            st.pop();
        }
        
        return ans;
        
    }
};