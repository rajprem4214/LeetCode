class Solution {
public:
    bool detectCapitalUse(string word) {
        int cnt=0;
         
        
        for(int i=0;i<word.length();i++)
        {
            if(isupper(word[i]))
                cnt++;
        }
        if(isupper(word[0]) && cnt==1)
            return true;
        
        if(cnt == word.length())
            return true;
       
        if(cnt == 0)
            return true;
        
        return false;
    }
};