// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int findTime(string S1, string S2) {
       // code here
       unordered_map<char,int>chId;
       for(int i=0;i<S1.size();i++)
       {
           chId[S1[i]]=i;
       }
       int timeSum=0;
       timeSum+=chId[S2[0]];//time for first key
       for(int i=0;i<S2.size()-1;i++)
       {
           timeSum+=abs(chId[S2[i]]-chId[S2[i+1]]);
       }
       return timeSum;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S1,S2;
        cin>>S1;
        cin>>S2;

        Solution ob;
        cout<<ob.findTime(S1,S2)<<endl;
    }
    return 0;
}  // } Driver Code Ends