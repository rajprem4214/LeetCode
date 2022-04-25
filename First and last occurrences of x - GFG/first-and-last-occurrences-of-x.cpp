// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
vector<int> find(int arr[], int n , int x )
{
    // code here
    
    int l = 0;
    int r = n-1;
    vector<int> ans;
    
    while(l <= r)
    {
        int mid = l + (r-l)/2;
        if(arr[mid] > x)
        r = mid-1;
        else if(arr[mid] < x)
         l = mid+1;
         else {
             if(mid ==0 || arr[mid]!=arr[mid-1])
             {
             ans.push_back(mid);
             break;
             }
             else
             r=mid-1;
           }
        
    }
    l=0,r=n-1;
    while(l <= r)
    {
        int mid = l + (r-l)/2;
       
       if(arr[mid] > x)
       r = mid-1;
       else if(arr[mid] < x)
       l = mid+1;
       else{
           if(mid == n-1 || arr[mid]!=arr[mid+1])
           {
               ans.push_back(mid);
               break;
           }
           else{
               l=mid+1;
           }
       }
    }
    
    if(ans.size() == 0)
    {
        ans.push_back(-1);
        ans.push_back(-1);
    }
    
  
    
    return ans;
    
}

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,x;
        cin>>n>>x;
        int arr[n],i;
        for(i=0;i<n;i++)
        cin>>arr[i];
        vector<int> ans;
        ans=find(arr,n,x);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}


  // } Driver Code Ends