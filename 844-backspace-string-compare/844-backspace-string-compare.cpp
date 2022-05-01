class Solution {
public:
   bool backspaceCompare(string s, string t) 
    {
        int i=0;    
        int j=0;
        
        for(int k=0;k<s.size();k++)
        {
            if(s[k]!='#')
            {
                s[i]=s[k];
                i++;
            }
            else if(i>0) i--;     // if back space found remove a character    
            
        }
         
        for(int k=0;k<t.size();k++)
        {
            
            if(t[k]!='#')
            {
                t[j]=t[k];
                j++;
            }
            else if(j>0) j--;            // if back space found remove a character  
     
        } 
              
        if(i!=j) return false;
        
        for(int k=0;k<i;k++)  //compare each character
        {
            if(s[k]!=t[k]) return false;
        }
        return true;
    }
};