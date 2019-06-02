// 用两个栈实现队列
// 题目：用两个栈实现一个队列。队列的声明如下，请实现它的两个函数appendTail
// 和deleteHead，分别完成在队列尾部插入结点和在队列头部删除结点的功能。
//
// 思路：有两个栈，stack1和stack2，每次插入一个元素，都插入到stack1
// 删除一个元素时：如果stack2为空，就把stack1的全部元素都弹出并压入stack2，
// 先入1的元素在1的底端，弹入2后就是在顶端，直接弹出就可以实现先入先出
// 如果stack2不为空，stack2中栈顶元素是最先进入队列的元素，可以弹出



class Solution
{
public:
    void push(int node) {
        stack1.push(node);
    }
 
    int pop() {
        if(stack2.size() <= 0) {
            while(stack1.size() > 0) {
                int& data = stack1.top();
                stack1.pop();
                stack2.push(data);
            }
        }
         
        int head = stack2.top();
        stack2.pop();
         
        return head;
    }
 
private:
    stack<int> stack1;
    stack<int> stack2;
};
