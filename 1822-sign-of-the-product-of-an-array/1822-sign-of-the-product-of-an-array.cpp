class Solution {
public:
    int arraySign(vector<int>& a) {
        int count = 0;
        for(int i = 0; i < a.size(); i++) 
        {
            if(a[i] == 0) return 0;
            if(a[i] < 0) count++;
        }
        return count%2 ? -1 : 1;
    }
};