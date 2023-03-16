class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {        //if there is no element in inorder or postorder traversal then it is a empty tree
       if(inorder.size()==0 || postorder.size()==0)
        return NULL;
//the last element of the postorder is the root of the tree 
        TreeNode* root= new TreeNode(postorder.back());
//if size of postorder is one than the tree is made up of only one node so insert it and return it 
        if(postorder.size()==1)
        return root;
//from starting of inorder to the end of inorder find the last value of the postorder also subtracting the first element index
        auto root1=find(inorder.begin(),inorder.end(),postorder.back())-inorder.begin();
//make the right inorder and left inorder tree
//firstly making the left_inorder,right_inorder,left_postorder and right_postorder array and then recursively calling the function to make the left and the right subtree 
//li--left_inorder,ri--right_inorder,lp--left_postorder,rp--right_postorder
        vector<int> li(inorder.begin(),inorder.begin()+root1);
        vector<int> ri(inorder.begin()+root1+1,inorder.end());
        vector<int> lp(postorder.begin(),postorder.begin()+root1);
        vector<int> rp(postorder.begin()+root1,postorder.end()-1);
        root->left=buildTree(li,lp);
        root->right=buildTree(ri,rp);
        return root ;
    }
};