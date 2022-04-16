class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
       int n = intervals.size();  // size of intervals vector
        vector<int> right(n, -1); // resultant vector initialized with value -1
        vector<pair<pair<int, int>, int>> vec;  // for storing the intervals corresponding to their indices
        for(int i = 0; i < n; i++)
            vec.push_back({{intervals[i][0], intervals[i][1]}, i});  // store
        sort(vec.begin(), vec.end()); // sort the vec on the basis of start
        for(int i = 0; i < n; i++)
        {
            int l = 0, r = n-1;  // binary search 
            while(l <= r)
            {
                int mid = l + (r-l)/2;
                if(vec[mid].first.first >= intervals[i][1])  // STARTj >= ENDi  (i could be equal to j)
                {
                    right[i] = vec[mid].second;  // store the answer
                    r = mid-1;  // trying to minimise the answer
                }
                else
                    l = mid+1;  // find in upper half of range
            }
        }
        return right;  // return the resultant vector 
    }
};