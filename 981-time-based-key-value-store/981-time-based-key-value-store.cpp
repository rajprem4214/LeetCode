class TimeMap {
public:
    unordered_map<string,unordered_map<int,string>>store;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        store[key][timestamp]=value;
    }
    
    string get(string key, int timestamp) {
        while(timestamp){
            if(store[key].find(timestamp)!=store[key].end()){
                return store[key][timestamp];
            }else{
                timestamp--;
            }
        }
        return "";
    }
};