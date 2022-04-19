class Solution {
public:
    string decodeString(string s) {
        stack<char> st;
        int i=0;
        
        while(i<s.length()){
            if(s[i]==']')
            {
                string str="";
                while(!st.empty() && st.top()!='[')   //finding the string which is enclosed by the bracket
                {
                    str+=st.top();
                    st.pop();
                }
                reverse(str.begin(),str.end());
                st.pop();
                
                string fre="";
                
                while(!st.empty() && st.top()>='0' && st.top()<='9')   //findind the frequency 
                {
                    fre+=st.top();
                    st.pop();
                }
                
                reverse(fre.begin(),fre.end());
                
                int fr=stoi(fre);
                
                for(int k=0;k<fr;k++)
                {
                    for(int j=0;j<str.length();j++)    //push the string fre number of times 
                    {
                        st.push(str[j]);
                    }
                }
                
            }else
            {
                st.push(s[i]);
            }
            
            i++;
        }
        
        string ans="";
        
        while(!st.empty())
        {
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};