/*
 * 232.用栈实现队列
 * 使用栈实现队列的下列操作：
 * push(x) -- 将一个元素放入队列的尾部。
 * pop() -- 从队列首部移除元素。
 * peek() -- 返回队列首部的元素。
 * empty() -- 返回队列是否为空。
 */

class MyQueue {
public:
    /** Initialize your data structure here. */
    MyQueue() {

    }

    /** Push element x to the back of queue. */
    void push(int x) {
        spush.push(x);
    }

    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        if (spop.empty()) {
            while(!spush.empty()) {
                int data = spush.top();
                spush.pop();
                spop.push(data);
            }
        }
        int top = spop.top();
        spop.pop();
        return top;
    }

    /** Get the front element. */
    int peek() {
        if (spop.empty()) {
            while(!spush.empty()) {
                int data = spush.top();
                spush.pop();
                spop.push(data);
            }
        }
        return spop.top();
    }

    /** Returns whether the queue is empty. */
    bool empty() {
        if (spush.empty() && spop.empty())
            return true;
        else
            return false;
    }
private:
    stack<int> spush;
    stack<int> spop;
};

