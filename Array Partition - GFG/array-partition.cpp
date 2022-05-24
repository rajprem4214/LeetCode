// { Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution{
    void update(int si , int ss , int se , int qi , int val ,int st[]){
        if(ss == se){
            st[si] = val;
            return;
        }
        int mid = (ss + se) / 2;
        if(qi <= mid)
        update(2 * si + 1 , ss  , mid , qi ,val , st);
        else
        update(2 * si + 2 , mid  + 1, se , qi , val , st);
        st[si] = (st[2 * si + 1] | st[2 * si + 2]);
    }
    int query(int si , int ss , int se , int qs , int qe , int st[]){
        if(qs > se ||  qe < ss)
        return 0;
        if(ss >= qs && se <= qe)
        return st[si];
        int mid = (ss + se) / 2;
        int l = query(2 * si + 1 , ss , mid , qs , qe , st);
        int r = query(2 * si + 2 , mid + 1 , se , qs , qe , st);
        return (l | r);
    }
    public:
    bool partitionArray(int n, int k, int m, vector<int> &A){
        // code here
        sort(A.begin() , A.end());
        vector<int>dp(n + 1 , 0);
        dp[n] = 1;
        int st[4 * (n + 2)] = {0};
        int j = n - 1;
        update(0 , 0 , n , n , dp[n] , st);
        for(int i = n - 1 ; i >= 0 ; i--){
            int ind1 = min(i + k - 1 , n);
            while(j >= 0 && A[j] - A[i] > m)
            j--;
            int ind2 = j;
            int ans = query(0 , 0 , n , ind1 + 1 ,ind2 + 1 , st);
            dp[i] = ans;
            update(0 , 0 , n , i ,dp[i], st);
        }
        return dp[0];
    }
};

// { Driver Code Starts.

int main(){
    int T;
    cin >> T;
    while(T--){
        int N, K, M;
        cin >> N >> K >> M;
        vector<int> A(N);
        for(int i = 0; i < N; i++){
            cin >> A[i];
        }
        Solution obj;
        bool ans = obj.partitionArray(N, K, M, A);
        if(ans){
            cout << "YES\n";
        }
        else{
            cout<< "NO\n";
        }
    }
}
  // } Driver Code Ends