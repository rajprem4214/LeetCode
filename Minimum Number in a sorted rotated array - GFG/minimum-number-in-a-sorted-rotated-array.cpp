// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


class Solution
{
    public:
    //Function to find the minimum element in sorted and rotated array.
    int minNumber(int arr[], int low, int high)
    {
        
        int ans =-1;
        // Your code here
        while(low <= high)
        {
            int mid = low + (high-low)/2;
            if(arr[0]<=arr[mid])
            low = mid+1;
            else
            {
                ans = arr[mid];
                high = mid-1;
            }
        }
        if(ans == -1)
        return arr[0];
        
        return ans;
    }
};

// { Driver Code Starts.


int main()
{
	
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;++i)
			cin>>a[i];	
		Solution obj;
		cout << obj.minNumber(a,0,n-1) << endl;
	}
	return 0;
}  // } Driver Code Ends