/*
输入一个链表，反转链表后，输出链表的所有元素。
*/


/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/
class Solution {
public:
    ListNode* ReverseList(ListNode* pHead) {
		if(!pHead)
            return NULL;
        ListNode *next,*pre=NULL;
        ListNode *cur=pHead;
        while(cur){
            next=cur->next;
            cur->next=pre;
            pre=cur;
            cur=next;
        }
        return pre;
    }
};
