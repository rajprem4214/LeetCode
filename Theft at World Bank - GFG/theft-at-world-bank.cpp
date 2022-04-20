// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
	public:
	long double maximumProfit(int N, long long C, vector<long long> w, vector<long long> p){
	    // Code here.
	   vector<pair<double,long long int >>v;
   int i;
   long long int x;
   double y,l,m;
   for(i=0;i<N;i++)
   {
       x=sqrt(w[i]);
       y=sqrt(w[i]);
       l=p[i];
       m=w[i];
       if(x==y)
       continue;
       else
       {
           v.push_back(make_pair((l/m),m));
       }
   }
   sort(v.begin(),v.end(),greater<pair<double,long long int >>());
   double ans=0;
   for(i=0;i<v.size();i++)
   {
       if(v[i].second <=C){
       ans+=v[i].second*v[i].first;         
       C-=v[i].second; } 
       else if (v[i].second >C)
       {
           ans+=C*v[i].first;
           break;
       }
   }
   return ans;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		long long C;
		cin >> n >> C;
		vector<long long > w(n), p(n);
		for(int i = 0; i < n; i++){
		    cin >> w[i] >> p[i];
		}
		Solution ob;
		long double ans = ob.maximumProfit(n, C, w, p);
		cout << fixed << setprecision(3) << ans << "\n";
	}  
	return 0;
}  // } Driver Code Ends