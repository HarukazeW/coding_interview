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
    TreeNode* KthNode(TreeNode* pRoot, int k)
    {
       if(k<=0)
           return NULL;
       return find_k(pRoot,k); 
    }
	TreeNode *find_k(TreeNode *pRoot,int &k) {
        if(!pRoot)
            return NULL;
        TreeNode *result=NULL;
        if(result=find_k(pRoot->left,k))
            return result;
        if(k==1)
           return pRoot;
        k--;
        return find_k(pRoot->right,k);
    }
    
};
