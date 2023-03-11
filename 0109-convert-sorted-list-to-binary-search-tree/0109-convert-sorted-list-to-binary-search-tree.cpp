class Solution {
private:
    /**
     * Recursively build subtree of height from vector
     * @params vec pointer to vector of values, includes values not in subtree
     * @params start starting index of subtree in vector
     * @params end ending index of subtree in vector
     **/
    TreeNode* buildSubTree(std::vector<int>* vec, size_t start, size_t end) {
        if (start >= end) {
			return nullptr;
		}

		// get middle value
		size_t mid = start + (end - start) / 2;

		// build tree
		TreeNode* root = new TreeNode(vec->at(mid));
		root->left = buildSubTree(vec, start, mid);
		root->right = buildSubTree(vec, mid + 1, end);
		return root;
    }

public:
    /* Convert sorted linked list to height-balanced binary search tree */
    TreeNode* sortedListToBST(ListNode* head) {
        // convert linked list to vector
        std::vector<int> vec = { };
        ListNode* curr = head;
        while (curr) {
            vec.push_back(curr->val);
            curr = curr->next;
        }

        // build binary search tree
        return buildSubTree(&vec, 0, vec.size());
    }
};