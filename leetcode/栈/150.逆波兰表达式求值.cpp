/*
 * @lc app=leetcode.cn id=150 lang=cpp
 *
 * [150] 逆波兰表达式求值
 * 思路：遍历，往栈中push，遇到操作符就从栈中弹出两个进行计算，再入栈
 */
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        std::stack<int> num_stack;
        int num1 = 0, num2 = 0;
        for (int i = 0; i < tokens.size(); i++) {
            if (tokens[i] == "+") {
                num1 = num_stack.top();
                num_stack.pop();
                num2 = num_stack.top();
                num_stack.pop();
                num_stack.push(num1 + num2);
            } else if (tokens[i] == "-") {
                num1 = num_stack.top();
                num_stack.pop();
                num2 = num_stack.top();
                num_stack.pop();
                num_stack.push(num2 - num1);
            } else if (tokens[i] == "*") {
                num1 = num_stack.top();
                num_stack.pop();
                num2 = num_stack.top();
                num_stack.pop();
                num_stack.push(num1 * num2);
            } else if (tokens[i] == "/") {
                num1 = num_stack.top();
                num_stack.pop();
                num2 = num_stack.top();
                num_stack.pop();
                num_stack.push(num2 / num1);
            } else  {
                num_stack.push(stoi(tokens[i]));
            }
        }
        if (num_stack.empty()) {
            return 0;
        }
        return num_stack.top();

    }
    /*
    int ston(string &s) {
        int num = 0;
        if (s[0] == '-') {
            for (int i = 1; i < s.length(); i++) {
                num = num * 10 + (s[i] - '0');
            }
            return -num;
        } else {
            for (int i = 0; i < s.length(); i++) {
                num = num * 10 + (s[i] - '0');
            }
            return num;  
        }
    }*/
};

