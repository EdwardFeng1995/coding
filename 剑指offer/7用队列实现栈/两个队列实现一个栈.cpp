// leetcode 225用队列实现栈
// 题目：使用队列实现栈的下列操作：

// push(x) -- 元素 x 入栈
// pop() -- 移除栈顶元素
// top() -- 获取栈顶元素
// empty() -- 返回栈是否为空
// 注意:

// 你只能使用队列的基本操作-- 也就是 push to back, peek/pop from front, size, 和 is empty 这些操作是合法的。
// 你所使用的语言也许不支持队列。 你可以使用 list 或者 deque（双端队列）来模拟一个队列 , 只要是标准的队列操作即可。
// 你可以假设所有操作都是有效的（例如, 对一个空的栈不会调用 pop 或者 top 操作）。


#include <iostream>
#include <queue>

using namespace std;

// 解法1:

class MyStack {
public:
    /** Initialize your data structure here. */
    MyStack() {
        
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        queue1.push(x);
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int topval;
        int s;
        if (!queue1.empty()) {
            s = queue1.size() - 1;
            for(int i = 0; i < s; i++) {
                queue2.push(queue1.front());
                queue1.pop();
            }
            topval = queue1.front();
            queue1.pop();
        } else  {
            for(int j = 0; j < queue2.size() - 1; j++) {
                s = queue2.size() - 1;
                queue1.push(queue2.front());
                queue2.pop();
            }
            topval = queue2.front();
            queue2.pop();
        }
        return topval;
    }
    
    /** Get the top element. */
    int top() {
        if (!queue1.empty())
            return queue1.back();
        else
            return queue2.back();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return (queue1.empty() && queue2.empty());
    }
    
private:
    std::queue<int> queue1;
    std::queue<int> queue2;
};

// 解法2
/*
class MyStack {
public:
    MyStack() {
        
    }
    
    void push(int x) {
        input.push(x);
        q2q(output, input);
        std::swap(input, output);
    }
    
    int pop() {
        int ret = output.front();
        output.pop();
        return ret;
    }
    
    int top() {
        return output.front();
    }
    
    bool empty() {
        return (input.empty() && output.empty());
    }
    
private:
    std::queue<int> input;
    std::queue<int> output;
    
    void q2q(queue<int> &a, queue<int> &b) {
        while(!a.empty()) {
            b.push(a.front());
            a.pop();
        }
    }
};
*/

// 解法3：
/*
class MyStack {
public:
    MyStack() {
        
    }
    
    void push(int x) {
        queue.push_back(x);
    }
    
    int pop() {
        int popval = top();
        queue.pop_back();
        return popval;
    }
    
    int top() {
        //if(empty())
        //   throw new exception("stack is empty");
        //else
            return queue.back();
    }
    
    bool empty() {
        if(queue.empty())
            return true;
        else
            return false;
    }
private:
    std::deque<int> queue;
};
*/


int main()
{
    MyStack* obj = new MyStack();

    obj->push(1);
    obj->push(2);
    obj->push(3);

    cout << obj->top() << endl;

    int i = obj->pop();
    cout << i << endl;
    cout << obj->top() << endl;
    
    cout << obj->pop() << endl;
    cout << obj->top() << endl;
    cout << obj->pop() << endl;

    cout << obj->empty() << endl;

    return 0;

}
