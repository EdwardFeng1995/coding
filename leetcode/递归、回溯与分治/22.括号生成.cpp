/*
 * @lc app=leetcode.cn id=22 lang=cpp
 *
 * [22] 括号生成
 * 思路：递归放置左括号和右括号
 *      递归限制条件：
 *      1. 左括号与右括号的数量，最多放置n个
 *      2. 只有在当前序列中的左括号数大于右括号数的时候加上右括号才能形成有效序列
 *         所以若左括号的数量<=右括号的数量，不可进行放置右括号的递归
 */
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        generate("", n, n, result);
        return result;
    }
private:
    void generate(string item, int left_num, int right_num, 
                  vector<string>& result) {
        if (left_num == 0 && right_num == 0) {
            result.push_back(item);
            return;
        }
        if (left_num > 0) {
            generate(item + '(', left_num-1, right_num, result);
        }
        if (left_num < right_num) {
            generate(item + ')', left_num, right_num-1, result);
        }
    }
};

