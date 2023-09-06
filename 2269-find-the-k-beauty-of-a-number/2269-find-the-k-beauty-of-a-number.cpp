class Solution {
public:
    int divisorSubstrings(int num, int k) {
        
        
        string n = to_string(num);
        int ans = 0;
        for(int i=0;i<n.size()-k+1;i++)
        {
            string st = n.substr(i, k);
            int sn = stoi(st);
            // cout<<sn<<endl;
            if(sn != 0)
            {
             if(num % sn == 0)
                ans++;   
            }
            
        }
        
        return ans;
    }
};