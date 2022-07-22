class Solution {
public:
    
    vector<int> res;

    void merge(vector<pair<int, int>> &nums, int l, int m, int r){
        
        int leftSize = m-l+1;
        int rightSize = r-m;
        
        vector<pair<int, int>> left;
        vector<pair<int, int>> right;
        
        for(int i=l;i<=m;i++){
            left.push_back(nums[i]);
        }
        
        for(int i=m+1;i<=r;i++){
            right.push_back(nums[i]);
        }
        
        int k = l;
        
        int numberLessThan = 0;
        
        int i = 0, j = 0;
        
        while(i<left.size()){
            while( j< right.size() && right[j].first < left[i].first){
                nums[k] = right[j];
                k++;
                j++;
                numberLessThan++;
            }
            res[left[i].second] += numberLessThan;
            nums[k] = left[i];
            i++;
            k++;
        }
        
        return;
        
    }
    
    void mergeSort(vector<pair<int, int>> &nums, int l, int r){
        
        if(l>=r) return;
        
        int m = (l+r)/2;
        
        mergeSort(nums, l, m);
        mergeSort(nums, m+1, r);
        merge(nums, l, m, r);
        
        return;
        
    }
    
    vector<int> countSmaller(vector<int>& nums) {
        res.resize(nums.size(), 0);
        vector<pair<int, int>> temp;
        for(int i=0;i<nums.size();i++){
            temp.push_back({nums[i], i});
        }
        mergeSort(temp, 0, nums.size()-1);
        return res;
    }
};