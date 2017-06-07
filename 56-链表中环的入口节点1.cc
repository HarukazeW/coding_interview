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
		set<ListNode*> snode;
        while(pHead){
            if(snode.count(pHead))
                return pHead;
            snode.insert(pHead);
            pHead=pHead->next;
        }
        return pHead;
    }
};
