class Solution {
public:

    int mod = 1e9 + 7;

    long long nCr(int n ,int r){
        long long sum = 1;
        for(int i=1;i<=r;i++){
            sum = mod_mul(sum, (n-r+i) );
            sum = mod_div(sum, i);
        }
        return sum;
    }

    long long mod_mul(long long a, long long b){
        a %= mod;
        b %= mod;
        a *= b;
        a %= mod;
        return a;
    }
    long long expo(long long a, long long b, long long mod) {
        int res = 1;
        while (b > 0){
            if (b & 1)
                res = (res * a) % mod; 
            a = (a * a) % mod;
            b = b >> 1;
        }
        return res;
    }

    long long mminvprime(long long a, long long b){
        return expo(a, b - 2, b);
    }
    long long mod_div(long long a, long long b){
        int m = mod;
        a = a % m;
        b = b % m;
        return (mod_mul(a, mminvprime(b, m)) + m) % m;
    }  //only for prime m


    long long split(vector<int> &a){

        if(a.empty())
            return 1;

        int f = a.front();
        vector<int> left, right;
        for(auto &x : a)
            if(x != f)
                if(x < f)
                    left.emplace_back(x);
                else
                    right.emplace_back(x);
        long long leftAns = split(left);
        long long rightAns = split(right);

        int l = left.size();
        int r = right.size();

        long long mergeAns = nCr(l+r,min(l,r));

        long long totalAns = mergeAns;

        totalAns = mod_mul(totalAns, leftAns);
        totalAns = mod_mul(totalAns, rightAns);

        return totalAns;
    }


    int numOfWays(vector<int>& nums) {
        return split(nums)-1;
    }
};