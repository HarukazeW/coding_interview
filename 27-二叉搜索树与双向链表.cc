/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
class Solution {
public:
    TreeNode* Convert(TreeNode* pRootOfTree)
    {
       if(!pRootOfTree) 
           return NULL;
        TreeNode *beg,*end;
        convert_recur(pRootOfTree,beg,end);
        return beg;
    }
    void convert_recur(TreeNode *root,TreeNode* &beg,TreeNode *&end){
        if(!root){
            beg=NULL;
            end=NULL;
            return;
        }
        
        TreeNode *begl,*endl,*begr,*endr;
        convert_recur(root->left,begl,endl);
        convert_recur(root->right,begr,endr);
        if(!begl) //has no left child 
            beg=root;
        else {
            beg=begl;
            root->left=endl;
            endl->right=root;
        }
        if(!begr) //has no right child
            end=root;
        else {
            end=endr;
            root->right=begr;
            begr->left=root;
        }
    }
};
