/* 
 * 155最小栈
 * 设计一个支持 push，pop，top 操作，并能在常数时间内检索到最小元素的栈。
 * push(x) -- 将元素 x 推入栈中。
 * pop() -- 删除栈顶的元素。
 * top() -- 获取栈顶元素。
 * getMin() -- 检索栈中的最小元素。
*/

class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {

    }


    void push(int x) {
        stackData.push(x);
        if (stackMin.empty()) {
            stackMin.push(x);
        } else if (x <= stackMin.top()) {
            stackMin.push(x);
        }
    }

    void pop() {
        if(stackData.top() == stackMin.top())
            stackMin.pop();
        stackData.pop();
    }

    int top() {
        return stackData.top();
    }

    int getMin() {
        return stackMin.top();
    }

private:
    stack<int> stackData;
    stack<int> stackMin;

};
