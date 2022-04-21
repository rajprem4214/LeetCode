class Solution {
public:
    int setBits(int n){
        int count = 0;
        while(n){
            if(n&1){
                count++;
            }
            n = n>>1;
        }
        return count;
    }
    vector<string> readBinaryWatch(int turnedOn) {
        vector<string> ans;
        for(int i = 0; i < 12; i++){
            
            for(int j = 0; j < 60; j++){
                string time = "";
                if(setBits(i) + setBits(j) == turnedOn){
                    time += to_string(i);
                    time += ":";
                    if(j < 10){
                        time += "0";
                    }
                    time += to_string(j);
                    ans.push_back(time);

                }
            
            }
        }
        return ans;
    }
};