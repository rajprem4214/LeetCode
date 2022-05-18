// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
public:
void helper(string sb,string s,vector<string> &vc){
    if(s.length()==0){
        vc.push_back(sb);
        return;
    }
    
    char c1 = s[0];
    helper(sb+" "+c1,s.substr(1),vc);
    helper(sb+c1,s.substr(1),vc);
}
    vector<string> permutation(string S){
        // Code Here
        vector<string> vc;
        string sb = "";
        sb += S[0];
        S = S.substr(1);
        helper(sb,S,vc);
        return vc;
    }
};

// { Driver Code Starts.

int  main(){
    int t;
    cin>>t;
    while(t--){
        string S;
        cin>>S;
        vector<string> ans;
        Solution obj;
        ans = obj.permutation(S);
        for(int i=0;i<ans.size();i++){
            cout<<"("<<ans[i]<<")";
        }
        cout << endl;
    }
}
  // } Driver Code Ends