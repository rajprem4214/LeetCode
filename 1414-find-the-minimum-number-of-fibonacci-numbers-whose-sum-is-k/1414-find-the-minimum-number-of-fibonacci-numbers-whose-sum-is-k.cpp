class Solution {
public:
    int findMinFibonacciNumbers(int k) {
        vector <int> vec;int ans = 0;
        int a = 1,b = 1,c = 0;
        vec.push_back(a);
        vec.push_back(b);
        while(c<=k){
            c = a+b;
            vec.push_back(c);
            a = b;
            b = c;
        }
        reverse(vec.begin(),vec.end());        
        for(int x : vec){
            if(x<=k){
                ans++;
                k-=x;
            }
        }
        return ans;
    }
};