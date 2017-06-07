class Solution {
public:
    bool IsBalanced_Solution(TreeNode* pRoot) {
		int deep;
        return recur_deepth(pRoot,deep);
    }
    
    bool recur_deepth(TreeNode* pRoot,int &deep){
        if(!pRoot){
            deep=0;
            return true;
        }
        int ldeep,rdeep;
        if(recur_deepth(pRoot->left,ldeep) && recur_deepth(pRoot->right,rdeep) 
           	&& abs(ldeep-rdeep)<=1) {
            //notice plus 1
            deep=max(ldeep,rdeep)+1;
            return true;
        }
        return false;
    }
};
