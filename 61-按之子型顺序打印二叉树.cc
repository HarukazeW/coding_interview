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
    vector<vector<int> > Print(TreeNode* pRoot) {
        vector<vector<int> > result;
        stack<TreeNode*> nodes1,nodes2;
        if(pRoot) {
            nodes1.push(pRoot);
            recur_zig_zag(result,nodes1,nodes2,false);
        }
        return result;
    }

    void recur_zig_zag(vector<vector<int>> &result,stack<TreeNode*> &source,stack<TreeNode*> &assist,bool reverse) {
        vector<int> temp;
        while(!source.empty()) {
            TreeNode *cur=source.top();
            source.pop();
            temp.push_back(cur->val);
//notice this
            if(reverse) {
     			if(cur->right)
                	assist.push(cur->right);
           		if(cur->left)
                	assist.push(cur->left);
            }
            else {
            	if(cur->left)
                	assist.push(cur->left);
           		if(cur->right)
               		assist.push(cur->right);
        	}
        }
        result.push_back(std::move(temp));
        if(!assist.empty())
            recur_zig_zag(result,assist,source,!reverse);
    }
    
};
