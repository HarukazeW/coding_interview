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
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
    {
		if(!pHead1 || !pHead2)
        	return pHead1?pHead1:pHead2;
        ListNode *result;
        if(pHead1->val<pHead2->val){
            result=pHead1;
            pHead1=pHead1->next;
        }
        else {
            result=pHead2;
            pHead2=pHead2->next;
        }
        ListNode *head=result;
        while(pHead1 && pHead2){
            if(pHead1->val < pHead2->val){
                result->next=pHead1;
                pHead1=pHead1->next;
            }
            else {
                result->next=pHead2;
                pHead2=pHead2->next;
            }
            result=result->next;
        }
        result->next = pHead1?pHead1:pHead2;
        //notice 此处返回的不是result
        return head;
    }
};
