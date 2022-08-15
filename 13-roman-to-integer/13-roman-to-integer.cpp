class Solution {
public:
    int romanToInt(string s) {
       int n = s.length();
        int sum = 0;
        map<char, int> roman;
        roman.insert(make_pair('I', 1));
        roman.insert(make_pair('V', 5));
        roman.insert(make_pair('X', 10));
        roman.insert(make_pair('L', 50));
        roman.insert(make_pair('C', 100));
        roman.insert(make_pair('D', 500));
        roman.insert(make_pair('M', 1000));

        for (int j = n - 1; j >=0; j--)
        {
            if(j>0 && roman[s[j]]<=roman[s[j-1]]){
                sum+=roman[s[j]];
            }
            else if(j>0 && roman[s[j]]>roman[s[j-1]]){
                sum+=(roman[s[j]]-roman[s[j-1]]);
                j--;
            }
            else{
                sum+=roman[s[0]];
            }
        }
        return sum;
    }
};