/**
*  struct ListNode {
*        int val;
*        struct ListNode *next;
*        ListNode(int x) :
*              val(x), next(NULL) {
*        }
*  };
*/
class Solution {
public:
    vector<int> printListFromTailToHead(ListNode* head) {
        vector<int> result;
        recur_print(result,head);
        return result;
    }
    void recur_print(vector<int> &result,ListNode* cur){
        if(!cur)
            return;
        recur_print(result,cur->next);
        result.push_back(cur->val);
    }
};
