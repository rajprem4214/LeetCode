class Solution {
public:
    int largestAltitude(vector<int>& gain) {
          gain.insert(gain.begin(),0);
        for(int i=1;i<gain.size();++i)
        {
            gain[i]+=gain[i-1];
        }
        //int val=*max(gain.begin(),gain.end());
        sort(gain.begin(),gain.end());
        return gain[gain.size()-1];
    }
};