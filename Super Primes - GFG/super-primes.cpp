// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++
class Solution{
public:	
	
void sieve(vector<int>& prime, int n){
	    vector<bool> is_prime(n+1, true);
	    is_prime[0] = is_prime[1] = false;
	    for(int i = 2; i*i <= n ; i++){
	        if(is_prime[i]){
    	        for(int j = i*i; j <= n; j+=i){
    	            is_prime[j] = false;
    	        }     
	        }
	    }
	    for(int i = 2; i <= n; i++){
	        if(is_prime[i] == true){
	            prime.push_back(i);
	        }
	    }
	}
	
	int superPrimes(int n)
	{
	    // Your code goes here
	    vector<int> prime;
	    sieve(prime, n);
	    int cnt = 0;
	    for(int i = 1; i < prime.size(); i++){
	        if(prime[i] - prime[i - 1] == 2)
	         cnt++;
	    }
	    return cnt;
	}
};

// { Driver Code Starts.

int main() 
{

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		int n;
   		cin >> n;
   		Solution ob;
   		cout << ob.superPrimes(n) << "\n";
   	}

    return 0;
}
  // } Driver Code Ends