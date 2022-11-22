class Solution {
public:
    int numSquares(int n) {
        auto isqrt = [](int n) { return (int)floor(sqrt(n)); };
        
        if (pow(isqrt(n),2) == n) return 1;
        
        for (int i = 1; i <= isqrt(n); ++i)
            if (n - i*i == pow(isqrt(n - i*i),2))
                return 2;
                
        while (n % 4 == 0) n /= 4;
        if   (n % 8 != 7) return 3; 
                
        return 4;  
    }
};