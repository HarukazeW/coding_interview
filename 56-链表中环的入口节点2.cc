/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};
*/
class Solution {
public:
    ListNode* EntryNodeOfLoop(ListNode* pHead)
    {
        if(!pHead)
            return NULL;
		ListNode *meet=meeting(pHead);
        if(!meet)
            return NULL;
       
        ListNode *pre=meet->next;
        int count=1;
        while(pre!=meet) {
            pre=pre->next;
            count++;
        }
        pre=pHead;
        ListNode *follow=pHead;
        while(count>0) {
            pre=pre->next;
            count--;
        }
        while(pre!=follow) {
            pre=pre->next;
            follow=follow->next;
        }
        return pre;
    }
    ListNode* meeting(ListNode *pHead) {
        ListNode *pre=pHead;
        ListNode *follow=pHead;
       		do  {
            if(!pre || !pre->next)
                return NULL;
            pre=pre->next->next;
            follow=follow->next;
        }  while(pre!=follow);
        return pre;
    }
};
