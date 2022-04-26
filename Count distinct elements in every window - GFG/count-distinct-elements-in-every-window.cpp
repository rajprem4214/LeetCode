// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



 // } Driver Code Ends

class Solution{
  public:
    vector <int> countDistinct (int arr[], int n, int k)
    {
        //code here.
        unordered_map<int, int> f;
        vector<int> res;
        
        // create map for the first window of k items
        for(int i = 0; i < k; i++) {
            if(f.find(arr[i]) == f.end())
                f[arr[i]] = 1;
            else
                f[arr[i]]++;
        }
        
        // distinct numbers count for first window
        int count = f.size();
        res.push_back(count);
        
        for(int i = k; i < n; i++) {
            // decrement count if item is being removed from map
            if(f[arr[i-k]] == 1) {
                f.erase(arr[i-k]);
                count--;
            }
            else {
                f[arr[i-k]]--;
            }

            // increment count if item is being freshly added to map
            if(f.find(arr[i]) == f.end()) {
                f[arr[i]] = 1;
                count++;
            } else {
                f[arr[i]]++;
            }
            
            // append the count for current window
            res.push_back(count);
        }
        
        return res;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        int n, k;
        cin >> n >> k;
        int a[n];
        for (int i = 0; i < n; i++) 
        	cin >> a[i];
        Solution obj;
        vector <int> result = obj.countDistinct(a, n, k);
        for (int i : result) 
        	cout << i << " ";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends