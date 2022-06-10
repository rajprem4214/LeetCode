class Solution {
public:
    int lengthOfLongestSubstring(string s) {
    vector<int> mp(128,-1);
        int left=0,right=0,len=0;
        int n=s.size();
        while(right<n){
            if(mp[s[right]]!=-1)
            left=max(left,mp[s[right]]+1);
            mp[s[right]]=right;
            len=max(len,(right-left+1));
            right++;
        }
        return len;
    }
};