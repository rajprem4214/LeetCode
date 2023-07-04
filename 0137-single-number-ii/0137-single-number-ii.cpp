class Solution {
public:
    int singleNumber(vector<int>& nums) {
       int res = 0;
        for (int i = 0; i <= 31; ++i)
        {
            int rightBit = 1 << i, count = 0;
            // counting the number of times 1 appear in the whole elements binar representation
            for (auto x : nums)
            {
                if (x & rightBit)
                    count += 1;
            }

            // adding the number to the result
            if (count % 3 == 1)
                res = res | rightBit;
        }

        return res; 
    }
};