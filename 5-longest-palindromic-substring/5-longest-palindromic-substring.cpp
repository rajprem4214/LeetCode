
class Solution {
public:
    string longestPalindrome(string s) {
        
        int left, right;
        
        
        int n=s.size();
                if(n==0)        //empty string
                return ""; 
        
        string res="";   //this will be our answer string
        for(int index=0;index<n;index++)
        {
            left= index;
            right = index;
          
            
            while(left>=0 && right<s.size()&& s[left]==s[right])
            {
                if(res.size()<(right-left+1))
                    res=s.substr(left, right-left+1);
                
                left--;
                right++;
            }
            
            
        }
        
        
             for(int index=0;index<n;index++)
        {
            left= index;
            right = index+1;
           
            
            while(left>=0 && right<s.size()&& s[left]==s[right])
            {
                if(res.size()<(right-left+1))
                    res=s.substr(left, right-left+1);
                
                left--;
                right++;
            }
            
            
        }
        
        return res;
		}
		};