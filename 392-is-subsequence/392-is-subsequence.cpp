class Solution {
public:
    
    // returns the length of longest common subsequence
    int isSubs(string& s1, string& s2, int i , int j,vector<vector<int>> &t)
    {
        if(i == 0 || j == 0)
            return 0;
        if(t[i][j] != -1)
            return t[i][j];
        if(s1[i-1] == s2[j-1])
            return t[i][j] = 1 + isSubs(s1,s2,i-1,j-1,t);
        else
            return t[i][j] = isSubs(s1,s2,i,j-1,t);
    }
    
    
    bool isSubsequence(string s1, string s2) {
        int m = s1.length();
        int n = s2.length();
        
        // intialising dp matrix with -1
        
        if(m >  n)
            return false;
        
        vector<vector<int>> t(m+1,vector<int> (n+1,-1));
    
        if(isSubs(s1,s2,m,n,t) == m)
            return true;
        return false;
    }
};