class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int h = letters.size()-1;
        int l = 0;
        int pos = -1;
        while(l<=h)
        {
            int m = l + (h-l)/2;
            if(letters[m] > target)
            {
                h = m-1;
                pos = m;
            }
              
            else 
                l = m+1;
        }
        // cout<<l<<endl;
        if(pos == -1)
            return letters[0];
        else
            return letters[pos];
    }
};