class Solution {
public:
    int minPartitions(string n) {
       char mx = '0';
        for(int i=0;i<n.length();i++){
            mx = max(mx,n[i]);
        }
        
        int ans = mx - '0';
        return ans;
        
        
        
    }
};