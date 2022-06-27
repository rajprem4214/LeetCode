class Solution {
public:
    int numberOfSteps(int num) {
     
        return num ? 31-__builtin_clz(num) + __builtin_popcount(num) : 0 ;
        
    }
};