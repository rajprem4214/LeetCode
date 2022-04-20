class Solution {
public:
    vector<int> grayCode(int n) {
       vector<int> ans;
        for(int i = 0; i < 1 << n; i++) 
			/*
			As we know that MSB remains the same and all other bits are XOR of current and next bit so
			we can right shift i by 1 unit and take XOR with i to get desried result
			*/
            ans.push_back(i ^ (i >> 1));
        return ans;
    }
    

    
};