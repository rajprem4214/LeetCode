// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution
{
public:
   vector<int>v;
   void solve(vector<int>arr,int sum, int i)
   {
       if(i==arr.size())
       {
           v.push_back(sum);
           return;
       }
       solve(arr,sum,i+1);
       solve(arr,sum+arr[i],i+1);
   }
   
   vector<int> subsetSums(vector<int> arr, int N)
   {
       solve(arr,0,0);
       sort(v.begin(),v.end());
       
       return v;
   }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0 ; i < N ; i++){
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr,N);
        sort(ans.begin(),ans.end());
        for(auto sum : ans){
            cout<< sum<<" ";
        }
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends