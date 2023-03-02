class Solution {
public:
    int compress(vector<char>& chars) {
        int j = 1;
        int count = 1, n = chars.size();
        for(int i=1; i<n; i++){
            while(i<n && chars[i] == chars[i-1]){
                i++;
                count++;
            }
            if (count > 1){
                string val = to_string(count);
                for(char x:val){
                    chars[j++] = x;
                }
                count = 1;
            }
            if (i<n){
                chars[j++] = chars[i];
            }
        }
        return j;
        
    }
};