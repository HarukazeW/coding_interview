//此题关键在于要建辅助栈
   //注意应当时刻用minstack.top()来获取此前最小变量，若要用min_value更新，
    //则应在pop操作时更新min_value值
class Solution {
public:
    stack<int> istack;
    stack<int> minstack;
    void push(int value) {
        if(minstack.empty() || value<minstack.top())
            minstack.push(value);
	else
	    minstack.push(minstack.top());
        istack.push(value);
    }
    void pop() {
        istack.pop();
        minstack.pop();
    }
    int top() {
        return istack.top();
    }
    int min() {
        return minstack.top();
    }

};
