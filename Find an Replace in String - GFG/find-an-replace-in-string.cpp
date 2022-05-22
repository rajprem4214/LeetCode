// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    string findAndReplace(string S ,int Q, int index[], string sources[], string targets[]) {
        bool ok=false;
        int c=0;
        
        for(int i=0;i<Q;i++){
            ok=false;
            for(int j=0;j<sources[i].size();j++)
            {  
                if(sources[i][j]!=S[j+index[i]+c]){
                ok=true;
                break;
            }
            }
            if(ok==false)
       {
        S.replace(index[i]+c, sources[i].size(), targets[i]);
        c+=targets[i].size()-sources[i].size();
        }
            
        }
        
        return S;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin>>S;
        
        int Q;
        cin>>Q;
        int index[Q];
        string sources[Q], targets[Q];
        
        for(int i=0; i<Q; i++)
            cin>>index[i];
        for(int i=0; i<Q; i++)
            cin>>sources[i];
        for(int i=0; i<Q; i++)
            cin>>targets[i];

        Solution ob;
        cout<<ob.findAndReplace(S,Q,index,sources,targets)<<endl;
    }
    return 0;
}  // } Driver Code Ends