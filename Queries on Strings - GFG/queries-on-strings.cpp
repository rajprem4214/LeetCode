// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
     void copy(vector<int> &s , vector<int> &d){
        for(int i = 0 ; i < 26 ; i++) d[i] = s[i];
    }
    int findUniqueChar(vector<int> &s , vector<int> &e){
        int count = 0;
        for(int i = 0 ; i < 26 ; i++){
            if(e[i] - s[i] > 0) count++;
        }
        return count;
    }
public:
vector<int>SolveQueris(string str, vector<vector<int>>Query){
	    int n = str.length();
	    vector<vector<int>> mp(n+1 , vector<int>(26+1));
	    for(int i = 1 ; i <= n ; i++){
	        copy(mp[i-1] , mp[i]);
	        mp[i][str[i-1] - 'a']++;
	    }
	    
	    vector<int> ans;
	    for(auto it : Query){
	        ans.push_back(findUniqueChar(mp[it[0]-1] , mp[it[1]]));
	    }
	    
	    return ans;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		int q;
		cin >> q;
		vector<vector<int>>Query;
		for(int i = 0; i < q; i++){
			int l, r;
			cin >> l >> r;
			Query.push_back({l, r});
		}
		Solution obj;
		vector<int> ans = obj.SolveQueris(str, Query);
		for(auto i: ans)cout << i << " ";
		cout << "\n";
	}
	return 0;
}  // } Driver Code Ends