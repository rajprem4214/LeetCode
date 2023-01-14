class Solution {
public:
    char min(char a , char b){
        return ((a < b) ? a : b);
    }
    char getParent(char c, vector<char> &parent){
        while(parent[c - 'a'] != c){
            c = parent[c - 'a'];
        }
        return c;
    }
    void updateParent(char a, char par, vector<char> &parent){
        while(parent[a - 'a'] != a){
            char temp = parent[a - 'a'];
            parent[a - 'a'] = par;
            a  = temp;
        }
        parent[a - 'a'] = par;
    }
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        vector<char> parent(26);
        for(int i=0;i<26;i++){
            parent[i] = 'a' + i ;
        }
        for(int i=0;i<s1.size();i++){
            char p1 = getParent(s1[i] , parent);
            char p2 = getParent(s2[i], parent);
            if(p1 < p2) updateParent(s2[i], p1, parent);
            else updateParent(s1[i], p2, parent);
        }
        string ans = baseStr;
        for(int i=0;i<baseStr.size();i++){
            ans[i] = getParent(baseStr[i], parent);
        }
        return ans;
    }
};