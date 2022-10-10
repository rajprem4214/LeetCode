class Solution {
public:
    string breakPalindrome(string palindrome) {
         int n=palindrome.size();
        
        if(n==1)
            return "";
        
       
        int c1=0;
        for(int i=0;i<n;i++)
        {
            if(palindrome[i]=='a')
                c1++;
        }
        
        if(c1==n ||  c1==n-1)
        {
            palindrome[n-1]='b';
            return palindrome;
        }
        
        int i=0;
        int j=n-1;
        int fg=0;
        while(i<j)
        {
            if(palindrome[i]!='a' && fg==0)
            {
                palindrome[i]='a';
                fg=1;
                break;
            }
            
            
            
            i++;j--;
        }
      
        return palindrome;
    }
};