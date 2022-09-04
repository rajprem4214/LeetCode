class Solution {
    struct node { int val, row;  };
    vector<vector<node>> left {{}};
    vector<vector<node>> right;
    
    static bool nodeLessThan(const node &l, const node &r) {
        if (l.row == r.row)
            return l.val < r.val;
        return l.row < r.row;
    }
    
    void insertLevel(vector<vector<node>> &book, int x, int y, int val) {
        if (y == book.size())
            book.resize(y + 1);
        
        book[y].push_back({val, x});
        sort(book[y].begin(), book[y].end(), nodeLessThan);
    }
    
    void order(TreeNode *root, int x, int y) {
        if (!root) return;
        if (y < 0) {
            const int dy = std::abs(y);
            assert ((dy) <= left.size());
            insertLevel(left, x, dy, root->val);
        } else {
            assert (std::abs(y) <= right.size());
            insertLevel(right, x, y, root->val);
        }
        
        order(root->left, x + 1, y - 1);
        order(root->right, x + 1, y + 1);
    }
    
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        order(root, 0, 0);
        
        vector<vector<int>> result;
        
        auto insert = [&](auto begin, auto end) {
            for (; begin != end; ++begin) {
                if (begin->empty())
                    continue;
                
                result.push_back({});
                for (const auto &node : *begin) 
                    result.back().push_back(node.val);
            }
        };
        
        // skip first item from left since that was the -0 the level
        insert(left.rbegin(), left.rend() - 1);
        insert(right.begin(), right.end());
            
        
        return result;
    }
};