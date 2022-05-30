class Solution {
public:
    int divide(int dividend, int divisor) {
        int q;
    if(dividend<=INT_MIN && divisor==-1)
    {

           return (INT_MIN+1)/divisor;
    }       
    else if(dividend>INT_MAX)
    {
       return INT_MAX;
    }

        q=dividend/divisor;
    return q;

    }
};