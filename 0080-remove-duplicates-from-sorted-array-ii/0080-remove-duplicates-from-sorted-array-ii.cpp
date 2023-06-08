class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
      int k=1,i=0,p=nums[0],c=1;
        for(i=1;i<nums.size();i++)
        {
            if(p==nums[i])
            {
                c++;
                if(c<=2)
                {
                    nums[k]=p;
                    k++;
                }  
            }
            else
            {
                c=1;
                p=nums[i];
                nums[k]=p;
                k++;
            }
        }
        return k;  
    }
};