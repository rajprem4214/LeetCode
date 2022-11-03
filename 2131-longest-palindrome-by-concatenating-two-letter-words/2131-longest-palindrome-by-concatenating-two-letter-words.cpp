class Solution
{
public:
    int longestPalindrome(vector<string> &words)
    {
        unordered_map<string, int> st;
        int count = 0;
        for (int i = 0; i < words.size(); ++i){
            string temp = { words[i].rbegin(),words[i].rend()};
            if (st.find(temp) != st.end()){
                count += 4;
                if (st[temp] == 1) st.erase(temp);
                else st[temp]--;
            }
            else{
                st[words[i]]++;
            }
        }
        for (auto &x: st){
            if (x.first[0] == x.first[1]){
            count += 2;
            return count;
            }
        }
        return count;
    }
};