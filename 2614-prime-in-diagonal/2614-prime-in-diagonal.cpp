class Solution {
public:
bool prime(int n)
{

    if (n <= 1)
        return false;
 
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0)
            return false;
    }
    return true;
} int diagonalPrime(vector<vector<int>>& nums) {
        long long maxi=0;
        for(int i=0;i<nums.size();i++)
        {
            for(int j=0;j<nums[i].size();j++)
            {
                if(i==j and prime(nums[i][j]))
                {
                   
                    if(nums[i][j]>maxi)
                        maxi=nums[i][j];
                }
                if(i+j==nums.size()-1 and prime(nums[i][j]))
                {
                         if(nums[i][j]>maxi)
                        maxi=nums[i][j];
                }
            }
        }
        return maxi;
        
    }
};