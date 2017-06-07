/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
		int plen=pre.size();
        int vlen=vin.size();
        if(plen!=vlen)
            return NULL;
        TreeNode *result=recur_construct(pre,vin,0,0,plen);
        return result;
    }
    TreeNode *recur_construct(vector<int> &pre,vector<int> &vin,int pi,int vi,int sz){
        if(sz<=0)
            return NULL;
        int num=pre[pi];
        int llen=0;
        while(vin[vi+llen]!=num){
            llen++;
        }
        int rlen=sz-llen-1;
        TreeNode *cur=(TreeNode*) malloc(sizeof(TreeNode));
        cur->val=num;
        cur->left=recur_construct(pre,vin,pi+1,vi,llen);
        cur->right=recur_construct(pre,vin,pi+1+llen,vi+llen+1,rlen);
        return cur;
    }
};
