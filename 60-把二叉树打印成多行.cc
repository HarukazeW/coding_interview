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
        	queue<TreeNode*> treeque;
            vector<vector<int> > result;
            vector<int> cur_res;
            if(!pRoot)
                return result;
            treeque.push(pRoot);
            treeque.push(NULL);
            //注意要考虑队列中只有一个元素，且其为NULL的情况
            while(!treeque.empty()) {
                TreeNode *cur=treeque.front();
                treeque.pop();
                if(!cur)
                    continue;
                cur_res.push_back(cur->val);
                if(cur->left)
                	treeque.push(cur->left);
                if(cur->right)
                    treeque.push(cur->right);
                if(!treeque.empty() && !treeque.front()) {//到达层末
                    treeque.pop();
                    result.push_back(std::move(cur_res));
                    cur_res.clear();
                    treeque.push(NULL);
                }
            }
            return result;
        }
    
};
