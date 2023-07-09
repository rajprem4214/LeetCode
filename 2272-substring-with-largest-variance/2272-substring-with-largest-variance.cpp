class Solution {
public:
        int a_minus_b(char a, char b, string& s) {
     //   cout<<a<<","<<b<<endl;
        int best_sum = 0;
        int a_count = 0, b_count = 0;
        for (char c : s) {
            if (c == a) a_count++;
            else if (c == b) b_count++;
            else continue;
            if (b_count > 0)
                best_sum = max(best_sum, a_count-b_count);
            else if ( b_count==0 ) //handle "bbaaaa" for previous b
                best_sum = max(best_sum, a_count-1);
            if (a_count < b_count ) {
                a_count = b_count = 0;
            }
        }
    //    cout<<best_sum<<endl;
        return best_sum;
    }

    int largestVariance(string s) {
        unordered_map<char, int> freq;
        for (char c : s){
            if (freq.count(c)==0) freq[c]=1;
            else freq[c]++;
        }
         
        int ans = 0;
        for (auto [a, fa]: freq) {
            for (auto [b, fb]: freq) {
                if (a!=b)
                    ans = max(ans, a_minus_b(a, b, s));
            }
        }
        return ans;
    
    }
};