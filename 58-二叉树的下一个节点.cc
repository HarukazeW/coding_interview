/*
struct TreeLinkNode {
    int val;
    struct TreeLinkNode *left;
    struct TreeLinkNode *right;
    struct TreeLinkNode *next;
    TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {
        
    }
};
*/
class Solution {
public:
    TreeLinkNode* GetNext(TreeLinkNode* pNode)
    {
        //TreeLinkNode *result;
        if(!pNode)
            return NULL;
        if(pNode->right){
            pNode=pNode->right;
            while(pNode->left)
                pNode=pNode->left;
        	return pNode;
        }
        //此处用while 而非else if
        while(pNode->next){
            if(pNode->next->left==pNode)
                return pNode->next;
            else 
                pNode=pNode->next;
        }
        return NULL;
    }
    
};
