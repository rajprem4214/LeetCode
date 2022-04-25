// { Driver Code Starts
#include<bits/stdc++.h>
 
using namespace std; 


bool findPair(int arr[], int size, int n);

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int l,n;
        cin>>l>>n;
        int arr[l];
        for(int i=0;i<l;i++)
            cin>>arr[i];
        if(findPair(arr, l, n))
            cout<<1<<endl;
        else cout<<"-1"<<endl;
    }
    
  
    return 0;
}// } Driver Code Ends


bool findPair(int arr[], int size, int n){
    //code
    sort(arr, arr+size);
    int l = 0;
    int h = 1;
   
    
    while(l<size && h<size){
        if(abs(arr[l] - arr[h]) == n && l!=h)
        return true;
        else if(abs(arr[l] - arr[h]) < n)
        h++;
        else
        l++;
    } 
    return false;
}