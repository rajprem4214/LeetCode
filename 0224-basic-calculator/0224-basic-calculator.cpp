class Solution {
public:
    int calculate(string s) {
        int n=s.size();
        int res=0,sign=1; 
        long int temp=0;//temp from storing current evaluated answer
        stack<int>st;
        for(int i=0;i<n;i++)
        {
            if(isdigit(s[i]))
            {   
                temp=s[i]-48;
                for(int j=i+1;j<n;j++)
                {
                    if(isdigit(s[j]))
                    {
                        temp*=10;
                        temp+=(s[j]-48);
                        i++;
                    }
                    else
                    break;
                }
                res+=temp*sign;
            }
            else if(s[i]=='+')
            sign=1;
            else if(s[i]=='-')
            sign=-1;
            else if(s[i]=='(')
            {   
                st.push(res);
                st.push(sign);
                res=0;
                sign=1;
            }
            else if(s[i]==')')
            {
                res*=st.top();
                st.pop();
                res+=st.top();
                st.pop();
            }
        }
        return res; 
    }
};