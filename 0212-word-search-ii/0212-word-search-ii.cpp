class TrieNode {
public:
    TrieNode* child[26];
    int cnt;
    int end;
    TrieNode() {
        for (int i = 0; i < 26; i++) {
            child[i] = NULL;
        }
        cnt = 0;
        end = 0;
    }
};

class Trie {
public:
    TrieNode* root = new TrieNode();
    void TrieInsert(string& s) {
        int n = s.length();
        TrieNode* p = root;
        for (int i = 0; i < n; i++) {
            int nxt = s[i] - 'a';
            if (p->child[nxt] == NULL) {
                p->child[nxt] = new TrieNode();
            }
            p = p->child[nxt];
            p->cnt++;
        }
        p->end++;
    }
    void TrieDelete(string& s) {
        int n = s.length();
        TrieNode* p = root;
        for (int i = 0; i < n; i++) {
            int nxt = s[i] - 'a';
            p = p->child[nxt];
            p->cnt--;
        }
     }
};

class Solution {
public:
    Trie* trie = new Trie();
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> res;  
        for (string w : words) {
            trie->TrieInsert(w);
        }
        TrieNode* root = trie->root;
        string s = "";
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                backtrack(board, i, j, s, root, res);
            }
        }
        return res;

    }
    void backtrack(vector<vector<char>>& board, int i, int j, string s, TrieNode* root, vector<string>& res) {
        if (!checkOk(i, j, board.size(), board[0].size()) || board[i][j] == ' ') {
            return;
        }
        root = root->child[board[i][j] - 'a'];
        if (root == NULL || root->cnt == 0) {
            return;
        }
        char tmp = board[i][j];
        s+=tmp;
        if (root->end > 0) {
            res.push_back(s);
            root->end--;
            trie->TrieDelete(s);
        }
        board[i][j] = ' ';
        backtrack(board, i-1, j, s, root, res);
        backtrack(board, i, j-1, s, root, res);
        backtrack(board, i+1, j, s, root, res);
        backtrack(board, i, j+1, s, root, res);
        board[i][j] = tmp;
    }
    bool checkOk(int i, int j, int m, int n) {
        if (i < 0 || i >= m || j < 0 || j >= n) {
            return false;
        }
        return true;
    }
};