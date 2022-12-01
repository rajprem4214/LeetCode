class Solution {
public:
    bool halvesAreAlike(string s) {
        int left=0,right = 0 ;
        
        for(int i=0;i<s.length()/2;i++)
        {
            if(s[i]=='a' || s[i]=='e' || s[i]=='o' || s[i]=='i' || s[i]=='u' || s[i]=='A' || s[i]=='E' || s[i]=='O' || s[i]=='I' || s[i]=='U')
                left++;
        }
        for(int i=s.length()/2;i<s.length();i++)
        {
            if(s[i]=='a' || s[i]=='e' || s[i]=='o' || s[i]=='i' || s[i]=='u' || s[i]=='A' || s[i]=='E' || s[i]=='O' || s[i]=='I' || s[i]=='U')
                right++;
        }
        if(left == right)
            return true;
        else
            return false;
    }
};