/*
 * 题目：合法的出栈序列
 *       已知从1至n的数字序列，按顺序入栈，每个数字入栈后即可出栈，也可在栈中停留，等待后面的数字入栈后，该数字再出栈
 *       判断该数字序列的出栈是否合法？
 * 
 * 思路：
 *       将出栈序列保存在data_queue队列中，设置一个模拟栈stack来模拟数字序列的入栈和出栈
 *       判断data_queue.front() 是否等于 stack.top()
 *       如果相等，则同时弹出
 *       如果不等，则继续入栈
 *       如果最终stack无法为空，则出栈序列不合法
 */

#include <iostream>
#include <stack>
#include <queue>

using namespace std;

bool check_is_valid_order(std::queue<int> &order)
{
    stack<int> s;
    int n = order.size();
    for (int i = 1; i < n; i++) {
        s.push(i);
        while (!s.empty() && order.front() == s.top()) {
            order.pop();
            s.pop();
        }
    }
    if (!s.empty()) {
        return false;
    }
    return true;
}

int main()
{
    queue<int> order;
    queue<int> order2;
    order.push(3);
    order.push(2);
    order.push(1);
    order.push(4);
    order.push(5);
    cout << check_is_valid_order(order) << endl;
    order2.push(3);
    order2.push(1);
    order2.push(2);
    order2.push(4);
    order2.push(5);
    cout << check_is_valid_order(order2) << endl;
    return 0;
}

