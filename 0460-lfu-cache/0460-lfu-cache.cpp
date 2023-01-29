class LFUCache {
private:
    unordered_map<int, pair<int, int>> kvfm;//{freq, val}
    unordered_map<int, list<int>::iterator> kim;
    unordered_map<int, list<int>> fkm;
    int minFreq;
    int cap;
public:
    LFUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) {
        if (kvfm.count(key) == 0) return -1;
        fkm[kvfm[key].first].erase(kim[key]);
        kvfm[key].first++;
        fkm[kvfm[key].first].push_back(key);
        kim[key] = --fkm[kvfm[key].first].end();
        
        if (fkm[minFreq].size() == 0)
            minFreq++;
        return kvfm[key].second;
    }
    
    void put(int key, int value) {
        if (cap <= 0) return;
        if (get(key) != -1) {
            kvfm[key].second = value;
            return;
        }
        if (kvfm.size() >= cap) {
            int tmp = fkm[minFreq].front();
            kvfm.erase(tmp);
            kim.erase(tmp);
            fkm[minFreq].pop_front();
        }
        kvfm[key] = {1, value};
        fkm[1].push_back(key);
        kim[key] = --fkm[1].end();
        minFreq = 1;
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */