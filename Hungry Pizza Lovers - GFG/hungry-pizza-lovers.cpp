// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


vector<int> permute(vector<vector<int>> &arr, int n);


int main() {
    
    int t;cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<vector<int>> arr(n);
        
        for(int i=0;i<n;i++)
        {
            int a, b;
            cin>> a>> b;
            arr[i].push_back(a);
            arr[i].push_back(b);
        }
        
        vector<int> ans;
        ans = permute(arr, n);
        for(int i=0;i<n;i++)
            cout << ans[i] << "\n";
        
    }
    
	return 0;
}// } Driver Code Ends


vector<int> permute(vector<vector<int>> &arr, int n)
{
    
   vector<int>v;
   vector<pair<int,int>>v1;
   int i=1;
   for(auto x:arr)
   {
       int q=x[0];
       int w=x[1];
       v1.push_back({q+w,i});
       i++;
   }
   sort(v1.begin(),v1.end());
   for(auto it:v1)
   {
       int z=it.second;
       v.push_back(z);
   }
   return v;
   
    
}