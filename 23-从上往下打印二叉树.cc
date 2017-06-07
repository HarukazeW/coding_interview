/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
//此题要注意队列的使用与函数
class Solution {
public:
    vector<int> PrintFromTopToBottom(TreeNode* root) {
        deque<TreeNode*> node_que;
        vector<int> result;
        if(!root)
            return result;
        node_que.push_back(root);
        while(!node_que.empty()){
            TreeNode *cur=node_que.front();
           	node_que.pop_front();
            result.push_back(cur->val);
            if(cur->left)
                node_que.push_back(cur->left);
            if(cur->right)
                node_que.push_back(cur->right);
        }
        return result;
    }
};
