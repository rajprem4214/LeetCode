class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        vector<long long> st;
        for(int i=0; i<tokens.size(); i++){
            int last = tokens[i].size()-1;
            if(isdigit(tokens[i][last])){
                st.push_back(stoi(tokens[i]));
            }
            else{
                int j = st.size();
                if(tokens[i]=="+") st[j-2]+=st[j-1];
                else if(tokens[i]=="-") st[j-2]-=st[j-1];
                else if(tokens[i]=="*") st[j-2]*=st[j-1];
                else if(tokens[i]=="/") st[j-2]/=st[j-1];
                st.pop_back();
            }
        }
        return st[0];
    }
};