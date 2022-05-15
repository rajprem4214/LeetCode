// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    void solve(vector<int> &arr, int n, int idx, vector<int> &temp_ans, set<vector<int>> &ans){
        if(idx==n){
            ans.insert(temp_ans);
            return;
        }
        temp_ans.push_back(arr[idx]);
        solve(arr, n, idx+1, temp_ans, ans);
        temp_ans.pop_back();
        solve(arr, n, idx+1, temp_ans, ans);
    }
    //Function to find all possible unique subsets.
    vector<vector<int> > AllSubsets(vector<int> arr, int n)
    {
        // code here
             sort(arr.begin(),arr.end());
        vector<int> temp_ans;
        set<vector<int>> s;
        solve(arr,n,0,temp_ans,s);
        vector<vector<int>> ans;
        for(auto x: s){
            ans.push_back(x);
            
        }
        return ans;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> A;
        int x;
        for(int i=0;i<n;i++){
            cin>>x;
            A.push_back(x);
        }
        Solution obj;
        vector<vector<int> > result = obj.AllSubsets(A,n);
        // printing the output
        for(int i=0;i<result.size();i++){
            cout<<'(';
            for(int j=0;j<result[i].size();j++){
                cout<<result[i][j];
                if(j<result[i].size()-1)
                    cout<<" ";
            }
            cout<<")";
        }
        cout<<"\n";
    }
}   


  // } Driver Code Ends