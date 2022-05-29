class Solution {
public:
    bool checkCommon(bitset<26> &a, bitset<26> &b){ // function to check if two bitset are common
        for(int i=0;i<26;i++) if(a[i] && b[i]) return true; // if any of the bits are true, return true
        return false; // otherwise return false
    }
    int maxProduct(vector<string>& words) { // function to find the maximum product
        int n = words.size(); // number of words
        int ans=0; // initialize the answer
        vector<bitset<26>> chars(n); // vector of bitset
        for(int i=0;i<n;i++){ // iterate over all the words 
            for(auto &ch:words[i]) // iterate over all the characters in the words[i]
                chars[i][ch-'a'] =1; // set the bitset to 1
            for(int j=0;j<i;j++) // now check with all the other words
                if(!checkCommon(chars[i],chars[j])) // if the two words are not common
                    ans = max(ans, (int)words[i].size()*(int)words[j].size()); // update the answer
        }
        return ans; // return the answer
    }
};