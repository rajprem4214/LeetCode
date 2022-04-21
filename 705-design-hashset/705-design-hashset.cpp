class MyHashSet {
public:
    int MOD;
    vector<vector<int>> stuff;
    MyHashSet() {
        MOD = 1000;
        stuff.resize(MOD);
    }
    
    void add(int key) {
        int myKey = key % MOD;
        for(int x : stuff[myKey]) {
            if(x == key) return;
        }
        stuff[myKey].push_back(key);
    }
    
    void remove(int key) {
        int myKey = key % MOD;
        auto it = find(stuff[myKey].begin(), stuff[myKey].end(), key);
        if(it != stuff[myKey].end()) {
            stuff[myKey].erase(it);
        }       
    }
    
    bool contains(int key) {
        int myKey = key % MOD;
        auto it = find (stuff[myKey].begin(), stuff[myKey].end(), key);
        return it != stuff[myKey].end();

    }
};