class Solution {
public:
   #define modulo 1000000007
    unsigned long long int expo(unsigned long long int x, int y, int p) {
        unsigned long long int res = 1;
        x = x % p;

        while(y > 0) {
            if(y & 1) 
                res = (res * x) % p;
            y = y >> 1;
            x = (x * x) % p;
        }
        return res;
    }

    unsigned long long int inverse(unsigned long long int n) {
        unsigned long long int ans = expo(n, modulo - 2, modulo);
        return ans ;
    }
    
    int numberOfWays(int s, int e, int k) {
        int extra = k - abs(e - s);
        if(extra % 2 != 0 || abs(e - s) > k) return 0;
        extra = abs(extra);
        
        unsigned long long int fact[k + 1];
        fact[0] = 1;
        for(int i = 1; i <= k; i++ ) {
            fact[i] = (fact[i - 1] * i) % modulo;
        }
        int ans = fact[k] * inverse(fact[extra/2]) % modulo;
        ans = ans * inverse(fact[k - (extra / 2)]) % modulo;
        ans = ans % modulo;
        return ans;
    }
};