class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        int n =  word1.size();
    int m = word2.size();
    
 string temp1 = "";
    for(int i =0; i< n ; i++)
    {
        temp1 +=word1[i];
    }
    
    string temp2= "";
    for(int i =0; i< m; i++)
    {
        temp2 +=word2[i];
    }
    
    if( temp1 ==temp2)
    {
        return true;
    }
    return false;
    }
};