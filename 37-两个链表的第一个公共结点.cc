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
    ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) {
        int count1=0;
        ListNode* pcur=pHead1;
        while(pcur){
			pcur=pcur->next;
            count1++;
        }
        pcur=pHead2;
        int count2=0;
        while(pcur){
            pcur=pcur->next;
            count2++;
        }
        int step=count1-count2;
        ListNode *pre=step>0?pHead1:pHead2;
        ListNode *follow=step>0?pHead2:pHead1;
        while(step>0){
            pre=pre->next;
            step--;
        }
        while(pre){
            if(pre==follow)
                return pre;
            pre=pre->next;
            follow=follow->next;
        }
        return NULL;
    }
};
