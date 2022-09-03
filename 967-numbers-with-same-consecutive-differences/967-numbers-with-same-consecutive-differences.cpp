class Solution {
public:
    vector<int> numsSameConsecDiff(int n, int k) {
        
        vector<int> ans;
        int len = 0;
        for(int i=1; i<=9; i++){
            DFS(n-1, k, ans, i);
        }
        return ans;
    }
    
    void DFS(int len, int &k, vector<int> &ans, int num){
        
        if( len == 0 ){
            ans.push_back(num);
            return;
        }
        
        int lastDigit = num%10;
        if( k ){
            if( (lastDigit + k) <= 9 ) DFS(len-1, k, ans, ((num*10) + (lastDigit + k)) );
            if( (lastDigit - k) >= 0 ) DFS(len-1, k, ans, ((num*10) + (lastDigit - k)) );
        }
        else{
            DFS(len-1, k, ans, ((num*10) + (lastDigit - k)) );
        }
    }
};