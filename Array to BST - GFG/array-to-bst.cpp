// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
private:
    void preorder(vector<int>&nums,vector<int>&ans,int l,int r){
        if(l>r)return;
        if(l==r){
            ans.push_back(nums[l]);
            return;
        }
        int mid=(r+l)/2;
        ans.push_back(nums[mid]);
        preorder(nums,ans,l,mid-1);
        preorder(nums,ans,mid+1,r);
        return;
    }
public:
    vector<int> sortedArrayToBST(vector<int>& nums) {
        // Code here
        vector<int>res;
        int l=0,r=nums.size()-1;
        preorder(nums,res,l,r);
        return res;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)cin >> nums[i];
		Solution obj;
		vector<int>ans = obj.sortedArrayToBST(nums);
		for(auto i: ans)
			cout << i <<" ";
		cout << "\n";
	}
	return 0;
}  // } Driver Code Ends