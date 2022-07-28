class Solution {
public:
    int maximumBags(vector<int>& c, vector<int>& r, int add) {
        int n = c.size(),count=0;
        transform(c.begin(), c.end(), r.begin(), r.begin(), minus<int>());
        sort(r.begin(), r.end());
        for(int i=0; i<n; i++)
        {
            if(add < r[i]) break;
            add -= r[i];
            count++;
        }
        return count;
    }
};