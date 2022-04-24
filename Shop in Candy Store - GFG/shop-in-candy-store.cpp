// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution
{
public:
    vector<int> candyStore(int candies[], int N, int K)
    {
        // Write Your Code here
       sort(candies,candies+N);
        int mini=0;
        int maxi=0;
        int i=0,j=N-1;
        while(i<=j){
            mini+=candies[i];
            i++;
            j-=K;
        }
        vector<int> v;
        v.push_back(mini);
        reverse(candies,candies+N);
        i=0,j=N-1;
        while(i<=j){
            maxi+=candies[i];
            i++;
            j-=K;
        }
        v.push_back(maxi);
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
        int N, K;
        cin >> N >> K;
        int candies[N];

        for (int i = 0; i < N; i++)
        {
            cin >> candies[i];
        }

        Solution ob;
        vector<int> cost = ob.candyStore(candies, N, K);
        cout << cost[0] << " " << cost[1] << endl;
    }
    return 0;
}  // } Driver Code Ends