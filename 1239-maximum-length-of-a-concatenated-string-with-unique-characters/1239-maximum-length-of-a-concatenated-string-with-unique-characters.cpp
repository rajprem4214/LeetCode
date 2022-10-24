class Solution {
public:
    int ans = 0;
    map<char,int>mp;
    int maxLength(vector<string>& arr) {
       int n = arr.size();
       string op="";
        solve(0,n,arr,op);
       return ans;
    }
    void solve(int i,int n,vector<string>arr,string op){
        if(i == n) return ;
        op+=arr[i];
        for(auto it : arr[i])
            mp[it]++;
        int f=0;
        for(auto it : mp){
            if(it.second > 1)
                f=1;
        }
        if(f == 0){
            ans = max(ans , (int)op.size());
            solve(i+1,n,arr,op);
        }
       
        for(auto it : arr[i]){
          mp[it]--;
          op.pop_back();
        }
        solve(i+1,n,arr,op);
    }
};