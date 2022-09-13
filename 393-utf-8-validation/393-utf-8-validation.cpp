class Solution {
public:
    int getMsbCount(int num){
        int count = 0;
        int k = 7;
        while(k){
            if((num>>k)&1)count++;
            else break;
            k--;
        }
        return count;
    }
    bool validUtf8(vector<int>& data) {
        
        int n = data.size();
        
        int start = 0;
        int mid = 0;
        
        while(mid<n){
            
            int num = data[mid];
            if(!(num>>7)&1){
                mid++;
                continue;
            }
            
            int count = getMsbCount(num);
            if(count == 1 || count>4)return false;
            mid++;
            count--;
            while(count > 0 && mid<n){
                int nextMsbCount = getMsbCount(data[mid]);
                if(nextMsbCount != 1)return false;
                mid++;
                count--;
            }
            
            if(count>0)return false;
        }
        
        return true;
    }
};