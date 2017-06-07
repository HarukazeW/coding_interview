/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/

//先查非叶节点的空孩子，这样直接忽略即可
//再检查是否是节点
//若非叶节点，再分别递归找其lchild和rchild
class Solution {
public:
    vector<vector<int> > FindPath(TreeNode* root,int expectNumber) {
		vector<vector<int>> result;
        vector<int> temp;
        find_path_recur(root,0,expectNumber,result,temp);
        return result;
    }
    void find_path_recur(TreeNode* root,int curr_total,int target,
                        vector<vector<int>> &result,vector<int> curr_path){
       	if(!root)
            return;
        curr_total+=root->val;
        curr_path.push_back(root->val);
        //leaf
        if(!root->left && !root->right){
            if(curr_total==target)
        //注意此处不该是std::move
                result.push_back(curr_path);
        }
    	else {
        	find_path_recur(root->left,curr_total,target,result,curr_path);
        	find_path_recur(root->right,curr_total,target,result,curr_path);
        }
        curr_path.pop_back();
    }
