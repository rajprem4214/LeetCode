class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> v;
        int l = 0, r = numbers.size() - 1;
        while(l < r)
        {
            if(numbers[l] + numbers[r] == target)
            {
                v.push_back(l+1);
                v.push_back(r+1);
                return v;
            }
            else if(numbers[l] + numbers[r] < target)
                l++;
            else
                r--;
        }
        return v;
    }
};