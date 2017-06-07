//不同之处在于只有当当前值小于等于minstack栈顶才入栈
//每次出栈时，检查当前元素与minstack栈顶元素是否相同，相同则minstack栈顶出栈
class Solution {
public:

    stack<int> istack;
    stack<int> minstack;
  //  int min_val=INT_MAX;
    void push(int value) {
        istack.push(value);
        if(minstack.empty() || value<=minstack.top())
      		minstack.push(value);
    }
    void pop() {
        if(istack.top()==minstack.top())
           minstack.pop();;
        istack.pop();  
    }
    int top() {
        return istack.top();
    }
    int min() {
        return minstack.top();
    }

};
