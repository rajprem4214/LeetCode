class Solution {
public:
    int minimumScore(string s, string t) {
        // check if t can become a subsequence of s after some removal
        // only right and left is required so no need to consider remaining ones 
        // in between
        // check for subsequence - if prefix does not overlap suffix
        int n=s.length(), m=t.length();
        vector<int> pref(m, n), suff(m, -1);
        int p1=0, p2=0;
        while(p2<m) // filling the prefix array
        {
            if(p1==n)
            break;
            if(s[p1] == t[p2])
            {
                pref[p2]=p1;
                p2++;
            }
            p1++;
        }
        p1=n-1, p2=m-1;
        while(p2>=0) // filling the suffix array
        {
            if(p1==-1)
            break;
            if(s[p1] == t[p2])
            {
                suff[p2]=p1;
                p2--;
            }
            p1--;
        }
        
        
        for(auto it:pref){
            cout<<it<<" ";
        }
        cout<<endl;
        
        for(auto it:suff){cout<<it<<" "; }cout<<endl;
            
        
        // binary search to find the left and right pointer that has to
        // be removed
        int ans=m; // since maximum answer is the length of t
        for(int l=0;l<m;l++) // fixing the left pointer
        {
            if(l>0 and pref[l-1]==n) // no need to check if we find a character we cannot form a subsequence with
            break;
            int ele=l==0?-1:pref[l-1]; // take the first valid suffix if left pointer is at index 0
            int r=upper_bound(suff.begin(), suff.end(), ele)-suff.begin(); // find the first element with value greater than that of pref[l-1]
            if(l==r) // it means whole string is subsequence of s
            return 0;
            ans=min(ans, r-l);
        }
        return ans;
    }
};