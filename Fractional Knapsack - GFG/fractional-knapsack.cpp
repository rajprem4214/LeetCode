// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Item{
    int value;
    int weight;
};


 // } Driver Code Ends
//class implemented
/*
struct Item{
    int value;
    int weight;
};
*/


class Solution
{
    public:
      static bool comp(pair<double, double>a, pair<double, double>b)
      {
          if(a.first/a.second > b.first/b.second)
          return true;
          else
          return false;
      }
    
    
    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        // Your code here
        
        vector<pair<double , double>> v;
        
        double res = 0.0;
        
        for(int i=0;i<n;i++){
            v.push_back({arr[i].value, arr[i].weight});
        }
        
        sort(v.begin(),v.end(),comp);
        
        for(int i=0;i<n;i++)
        {
            if(v[i].second <= W){
            res += v[i].first;
                W -= v[i].second;
            }else{
                if(W!=0)
                res+= (W*(v[i].first / v[i].second));
                W=0;
                break;
            }
        }
        
        return res;
        
    }
        
};


// { Driver Code Starts.
int main()
{
	int t;
	//taking testcases
	cin>>t;
	cout<<setprecision(2)<<fixed;
	while(t--){
	    //size of array and weight
		int n, W;
		cin>>n>>W;
		
		Item arr[n];
		//value and weight of each item
		for(int i=0;i<n;i++){
			cin>>arr[i].value>>arr[i].weight;
		}
		
		//function call
		Solution ob;
		cout<<ob.fractionalKnapsack(W, arr, n)<<endl;
	}
    return 0;
}  // } Driver Code Ends