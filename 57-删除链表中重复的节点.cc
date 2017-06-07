/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};
*/

//notice 1 1 2 2 3 3
class Solution {
public:
    ListNode* deleteDuplication(ListNode* pHead)
    {
		if(!pHead)
            return pHead;
		ListNode *cur=pHead,*pre=NULL;
        pHead=NULL;
        while(cur) {
            //ListNode *next=pNode->next;
            //每次用pre保存上个不须删除的节点，每次对cur进行检查
            if(!cur->next || cur->next->val!=cur->val) {
                //only in there we can confirm the cur won't be deleted
                if(!pHead)
                    pHead=cur; //置头指针
            	pre=cur;
                cur=cur->next;
                continue;
            }
            
            //will delete cur
            int val=cur->val;
            while(cur && cur->val==val) {
            	ListNode *next=cur->next;
                delete cur;
                cur=next;
            }
            if(pre) // for example,if we delete 2,2 ,we connect 1 and 3
                pre->next=cur;
        }
        return pHead;
        }
		
};
