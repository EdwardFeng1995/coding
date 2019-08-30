 /*
 * @lc app=leetcode.cn id=224 lang=cpp
 *
 * [224] 基本计算器
 * 思路：利用栈来去括号（一个数字栈，一个操作符栈），同时利用状态机转换思想
 * 1. 无括号时候，就是数字栈只要有两个了，就和操作符计算，结果push到数字栈，再按顺序入栈反复循环
 * 2. 设置一个计算标志位compute_flag，遇到±，flag=1，遇到( 不可以计算， flag=0，此时，数字栈与操作符栈继续push，直到遇到)才可以计算
 *  
 */
class Solution {
public:
    int calculate(string s) {
        static const int STATE_BEGIN = 0;      
        static const int NUMBER_STATE = 1;
        static const int OPERATION_STATE = 2;      // 分别定义开始状态，数字状态，操作符状态
        std::stack<long int> number_stack;
        std::stack<char> operation_stack;   // 数字栈和操作符栈
        long int number = 0;
        int STATE = STATE_BEGIN;
        int compuate_flag = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == ' ') {
                continue;   // 遇到空格就跳过
            }
            switch(STATE) {
                case STATE_BEGIN:   // 开始状态
                    if (s[i] >= '0' && s[i] <= '9') {
                        STATE = NUMBER_STATE;     // 转为数字态
                    } else {  
                        STATE = OPERATION_STATE;  // 转为操作态
                    }
                    i--;  // 回退，因为转移到对应状态没处理，所以需要退回来处理
                    break;
                case NUMBER_STATE:   //数字态
                    if (s[i] >= '0' && s[i] <= '9') {
                        number = number * 10 + s[i] - '0';  // 数字字符转换为数字
                    } else {   //  遇到操作符
                        number_stack.push(number);   // 将数字push进数字栈
                        if (compuate_flag == 1) {    // 计算标志为1
                            compute(number_stack, operation_stack);  // 计算
                        }
                        number = 0;  // 清零
                        i--;  // 回退
                        STATE = OPERATION_STATE;  // 状态转移到操作态
                    }
                    break;
                case OPERATION_STATE:  // 操作态
                if (s[i] == '+' || s[i] == '-') {   // ±操作符
                    operation_stack.push(s[i]);
                    compuate_flag = 1;
                } else if (s[i] == '(') {   // 遇到左括号，计算标志位置0
                    STATE = NUMBER_STATE;
                    compuate_flag = 0;
                } else if (s[i] >= '0' && s[i] <= '9') {
                    STATE = NUMBER_STATE;
                    i--;
                } else if (s[i] == ')') {
                    compute(number_stack, operation_stack);
                }
                break;
            }
        }

        if (number != 0) {
            number_stack.push(number);
            compute(number_stack, operation_stack);
        }
        if (number == 0 && number_stack.empty()) {
            return 0;
        }
        return number_stack.top();
    }

    void compute(std::stack<long int> &number_stack, std::stack<char> &operation_stack) {
        if (number_stack.size() < 2) {
            return;
        }
        long int num2 = number_stack.top();
        number_stack.pop();
        long int num1 = number_stack.top();
        number_stack.pop();
        if (operation_stack.top() == '+') {
            number_stack.push(num1 + num2);
        } else if (operation_stack.top() == '-') {
            number_stack.push(num1 - num2);
        }
        operation_stack.pop();
    }
};

