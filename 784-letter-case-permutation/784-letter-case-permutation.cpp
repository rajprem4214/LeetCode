class Solution {
public:
    vector<string>ans;
    
     void solve(int i,string s,string str){
        
         if(i==s.length())
         {
             ans.push_back(str);
             return;
         }
         
         if(s[i]>='0' && s[i]<='9')
         {
             solve(i+1,s,str+s[i]);
         }
         
         else if(s[i]>='a' && s[i]<='z')
         {
             solve(i+1,s,str+s[i]);
             char a = toupper(s[i]);
           solve(i+1,s,str+a);
         }
         else if(s[i]>='A' && s[i]<='Z')
         {
             solve(i+1,s,str+s[i]);
             char a = tolower(s[i]);
             solve(i+1,s,str+a);
         }
         
     }
    
    
    
    
    vector<string> letterCasePermutation(string s) 
    {
     string str="";          
        solve(0,s,str);
        return ans;
    
        
    }
};