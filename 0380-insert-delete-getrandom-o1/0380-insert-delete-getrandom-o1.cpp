class RandomizedSet {
public:
    RandomizedSet() {}
    
    bool insert(int val) {
        if(rmap.find(val) == rmap.end()){
            rmap[val] = rvec.size();
            rvec.push_back(val);
            return true;
        }
        return false;
    }
    
    bool remove(int val) {
        if(rmap.find(val) != rmap.end()){
            rmap[rvec.back()] = rmap[val];
            swap(rvec[rmap[val]], rvec.back());
            rvec.pop_back();
            rmap.erase(val);
            return true;
        }
        return false;
    }
    
    int getRandom() {
        return rvec[rand()%rvec.size()];
    }
private: 
    unordered_map<int, int> rmap;
    vector<int> rvec;
};
/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */