// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{
public:
    string remove(string s){
        // code here
        char ch;
    	string ans="";
    	bool changed=false;
    	int i=0;
	    while(i<s.length())
	    {
	        if(i+1<s.length() && s[i]!=s[i+1])
	        {
	            ans+=s[i];
	            i++;
	        }
	        else if(i+1<s.length() && s[i]==s[i+1])
	        {
	            changed=true;
	            ch= s[i];
	            while(s[i]==ch)
	                i++;
	        }
	        else if(i+1 == s.length())
	            ans+=s[i++];
	    }
        if(changed)
            return remove(ans);
        else
            return ans;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    string tc;
    getline(cin, tc);
    t = stoi(tc);
    while (t--) {
        string s;
        getline(cin, s);
        Solution ob;
        cout << ob.remove(s) << "\n";
    }
    return 0;
}  // } Driver Code Ends