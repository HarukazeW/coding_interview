/*
struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
            label(x), next(NULL), random(NULL) {
    }
};
*/
class Solution {
public:
    RandomListNode* Clone(RandomListNode* pHead)
    {
        if(!pHead)
            return NULL;
        RandomListNode *next=NULL,*cur=pHead;
        //copy
        //注意验证非空是 cur而不是！cur
        while(cur){
        	RandomListNode *copy_cur=(RandomListNode*)malloc(sizeof(RandomListNode));
        	copy_cur->next=cur->next;
            cur->next=copy_cur;
            copy_cur->label=cur->label;
            cur=copy_cur->next;
        }
        //copy random
        cur=pHead;
        while(cur){
            //notice to thought if cur->random is null
	//记得一定要考虑cur->random 可能为空
            if(!cur->random)
                cur->next->random=cur->random;
            else
          		cur->next->random=cur->random->next;
            cur=cur->next->next;
        }
        //delete
       	cur=pHead;
        RandomListNode *pHead_copy=cur->next;
        cur->next=pHead_copy->next;
        RandomListNode *copy_pre=pHead_copy;
        cur=cur->next;
        while(cur){
            copy_pre->next=cur->next;
            copy_pre=copy_pre->next;
            cur->next=copy_pre->next;
            cur=cur->next;
        }
        //copy_pre->next=NULL;
        return pHead_copy;
    }
};
