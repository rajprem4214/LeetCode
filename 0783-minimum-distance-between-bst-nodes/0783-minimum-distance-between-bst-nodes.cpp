class Solution {
public:
    vector<int> v;
    void getValues(TreeNode* root)
    {
        if(root == NULL) return;
        v.push_back(root->val);
        getValues(root->left);
        getValues(root->right);
    }

    int minDiffInBST(TreeNode* root) {
        getValues(root);
        sort(v.begin(), v.end(), greater<>());
        int min = INT_MAX;
        for(int i = 0; i < v.size() - 1; i++)
        {
            int temp = v[i] - v[i + 1];
            if(temp < min)
                min = temp;
        }

        return min;
    }
};



