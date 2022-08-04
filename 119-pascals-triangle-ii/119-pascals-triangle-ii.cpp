class Solution {
public:
    vector<int> getRow(int rowIndex) {
       if(rowIndex == 0) return {1};
        if(rowIndex == 1) return {1, 1};
        vector<int> base = {1, 1};
        
        while(rowIndex >= 2) {
            int len = base.size()+1;
            for(int i = len-2; i > 0; i--) {
                base[i] = base[i-1] + base[i];
            }
            base.push_back(1);
            rowIndex--;
        }
        
        return base;
    }
};