class Solution {
public:
    int countVowelStrings(int n) {
       // base case for n = 1, possible ways of string starting with 'a,e,i,o,u'
        vector<int>track = {1,1,1,1,1};
        
        // intital track sum value 5
        int count = 5;
        
        // loop from 2 to N to generate result
        for(int i=2;i<=n;i++)
        {
            int tmp;
            
            // each char can have track[j to 5] sum of previous step in the current step 
            for(int j=0;j<5;j++)
            {
                tmp = count;
                count-=track[j];
                track[j] = tmp;
            }
            
            // update count for current step
            count = accumulate(track.begin(),track.end(),0);
        }
        
        return count;
     
    }
};