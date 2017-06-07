//注意是根据popV来确定要不要继续压栈
class Solution {
public:
    bool IsPopOrder(vector<int> pushV,vector<int> popV) {
        stack<int> istack;
        int len=pushV.size();
        for(int i=0,j=0;i<len;i++){
            istack.push(pushV[i]);
            while((!istack.empty()) && (istack.top()==popV[j])) {
                j++;
                istack.pop();
            }
        }
        if(!istack.empty())
            return false;
        return true;
    }
};
