class SnapshotArray {
public:

    vector<map<int,int>>A;
    // snap_id
    int s_id = 0;

    SnapshotArray(int length) {
        
        // resizing the array to the given length
        A.resize(length);

        // intializing all the elements with 0;
        for(int i = 0; i < length; i++)
            A[i][0] = 0;
        
    }
    
    void set(int index, int val) {

      // setting value at the given index with current snap_id
        A[index][s_id] = val;
    }
    
    int snap() {
        s_id++;
        return  s_id - 1;
    }
    
    int get(int index, int snap_id) {



        if(A[index].find(snap_id) == A[index].end())
        {
            auto it = --A[index].lower_bound(snap_id);
            return it->second;
        }
        return A[index][snap_id];
    }
};