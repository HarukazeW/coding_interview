/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};
*/
class Solution {
public:
    bool isSymmetrical(TreeNode* pRoot)
    {
    	if(!pRoot)
            return true;
        return isSymetrical(pRoot->left,pRoot->right);
    }
    bool isSymetrical(TreeNode *left,TreeNode *right){
        if(!left && !right)
            return true;
        if(!left || !right)
            return false;
        //notice should check the value
        if(left->val!=right->val)
            return false;
        return isSymetrical(left->left,right->right) && isSymetrical(left->right,right->left);
    }

};
