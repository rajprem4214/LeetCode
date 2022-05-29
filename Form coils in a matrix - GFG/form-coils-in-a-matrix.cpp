// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    vector<vector<int>> formCoils(int n) {
        
         vector<int> first,second;
        int m=2;
        
        vector<vector<int>> mat(4*n,vector<int>(4*n));
        int count=1;
        for(int i=0;i<4*n;i++){
            for(int j=0;j<4*n;j++)
                mat[i][j]=count++;
        }
        int i=(4*n)/2;
        int j=((4*n)/2)-1;
        
        first.push_back(mat[i][j]);
        char indicate='u';
        
        // for first coil
        while(true){
            // up
            bool flag=false;
            if(indicate=='u'){
                for(int k=1;k<=m;k++){
                    i--;
                    first.push_back(mat[i][j]);
                }
                indicate='r';
            }
            //right
            if(indicate=='r'){
                for(int k=1;k<=m;k++){
                    j++;
                    first.push_back(mat[i][j]);
                }
                indicate='d';
                m+=2;
            }
            //down
            if(indicate='d'){
                for(int k=1;k<=m;k++){
                    i++;
                    first.push_back(mat[i][j]);
                    if(mat[i][j]==(4*n*4*n)){
                        flag=true;
                        break;
                    }
                }
                indicate='l';
            }
            if(flag)
                break;
            //left
            if(indicate=='l'){
                for(int k=1;k<=m;k++){
                    j--;
                    first.push_back(mat[i][j]);
                }
                indicate='u';
                m+=2;
            }
        }
        vector<vector<int>> ans;
        ans.push_back(first);
        
        
        // for second coil
        i=((n*4)/2)-1;
        j=(n*4)/2;
        second.push_back(mat[i][j]);
        m=2;
        indicate='d';
        while(true){
            bool flag=false;
            if(indicate=='d'){
                for(int k=1;k<=m;k++){
                    i++;
                    second.push_back(mat[i][j]);
                }
                indicate='l';
            }
            if(indicate=='l'){
                for(int k=1;k<=m;k++){
                    j--;
                    second.push_back(mat[i][j]);
                }
                indicate='u';
                m+=2;
            }
            if(indicate=='u'){
                for(int k=1;k<=m;k++){
                    i--;
                    second.push_back(mat[i][j]);
                    if(mat[i][j]==1){
                        flag=true;
                        break;
                    }
                }
                indicate='r';
            }
            if(flag)
                break;
                
            if(indicate=='r'){
                for(int k=1;k<=m;k++){
                    j++;
                    second.push_back(mat[i][j]);
                }
                indicate='d';
                m+=2;
            }
        }
        ans.push_back(second);
        
        return ans;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        
        cin>>n;

        Solution ob;
        vector<vector<int>> ptr = ob.formCoils(n);
        
        for(auto it: ptr)
        {
            for(int i: it)
                cout<<i<<" ";
            cout<<endl;
        }
    }
    return 0;
}  // } Driver Code Ends