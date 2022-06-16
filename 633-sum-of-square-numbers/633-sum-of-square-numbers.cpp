class Solution {
public:
    bool judgeSquareSum(int c) {
        
         int n=sqrt(c);
        for(int i=0;i<=n;i++)
        {
            int j= sqrt(c-(i*i));
            if((i*i)+(j*j)==c)
                return true;
        }
        return false;
    
        
    }
};