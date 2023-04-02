class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int n = spells.size();
        int m = potions.size();
        sort(potions.begin(),potions.end());
        vector<int> pairs;
        for(int i=0;i<n;i++){
            int low = 0;
            int high = m-1;
            int mid;
            while(low<=high){
                mid = low + (high-low)/2;
                if((long long)spells[i]*potions[mid]>=success){
                    high = mid-1;
                }
                else{
                    low = mid+1;
                }
            }
            
            pairs.push_back(m-low);
        }

        return pairs;
    }
};
