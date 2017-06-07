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

//hhhh,直接把int指针当作char指针传参，再解析回int hhh
class Solution {
public:
    char* Serialize(TreeNode *root) {  
    	int *s=new int[200];
        int index=0;
        recur_serial(root,s,index);
        s[index]='\0';//notice
        return (char*)s;
    }
    
    void recur_serial(TreeNode *root,int *s,int &index) {
       if(!root) {
           s[index++]=INT_MAX;
           return;
       }
       s[index++]=root->val;
       recur_serial(root->left,s,index);
       recur_serial(root->right,s,index);
    }
    
    TreeNode* Deserialize(char *str) {
        int *s=(int*)str;
    	if(!s)
            return NULL;
        return recur_deserial(s);
    }
    
    TreeNode* recur_deserial(int *&s) {
        if(*s==INT_MAX) {
            s++;
            return NULL;
        }
       	TreeNode *root=(TreeNode*)malloc(sizeof(TreeNode));
        root->val=*(s++);
        root->left=recur_deserial(s);
        root->right=recur_deserial(s);
        return root;
    }
    
};
