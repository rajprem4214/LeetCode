// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++
#define mod 1000000007
class Solution{
public:
    bool checkPrime(long long val){
        if(val <= 2) return true;
        for(int i = 2 ; i <= ceil(sqrt(val)) ; i++){
            if(val % i == 0) return false;
        }
        return true;
    }
    long long primeProduct(long long L, long long R){
        long long int val = 1;
        for(long long i = L ; i <= R ; i++){
            if(checkPrime(i)) {
                // cout << i << "\n";
                val *= (i % mod);
            }
            val %= mod;
        }
        return val;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        long long L, R;
        cin>>L>>R;
        
        Solution ob;
        cout<<ob.primeProduct(L, R)<<"\n";
    }
    return 0;
}  // } Driver Code Ends