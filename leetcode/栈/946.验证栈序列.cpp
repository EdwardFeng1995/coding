/*
 * @lc app=leetcode.cn id=946 lang=cpp
 *
 * [946] 验证栈序列
 */

// @lc code=start

// 思路：
// 依次把pushed序列中的元素入栈，在入栈的过程中判断栈顶元素是否和popped中要下一个pop的元素相同，如果相同则pop
// 最后判断栈是否为空，是空，则符合。
class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int size = pushed.size();
        stack<int> s;
        int j = 0;
        for (auto i : pushed) {
            s.push(i);
            while (!s.empty() && s.top() == popped[j] && j < size) {
                s.pop();
                j++;
            }
        }
        return s.empty();
    }
};

// 剑指offer思路
// 如果下一个弹出的数字刚好是栈顶数字，那么直接弹出；
// 如果下一个弹出的数字不在栈顶，则把压栈序列中还没入栈的数字压入辅助栈直到把下一个需要弹出的数字压入栈顶为止；
// 如果所有数字都压如栈后仍然没有找到下一个弹出的数字，那么该序列不可能是一个弹出序列
class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        if (pushed.empty() && popped.empty()) {
            return true;
        }
        bool ans = false;
        if (!pushed.empty() && !popped.empty()) {
            int pNextPush = 0;
            int pNextPop = 0;
            stack<int> sdata;
            while (pNextPop < popped.size()) {
                while (sdata.empty() || popped[pNextPop] != sdata.top()) {
                    if (pNextPush == pushed.size()) {
                        break;
                    }
                    sdata.push(pushed[pNextPush]);
                    pNextPush++;
                }
                if (sdata.top() != popped[pNextPop]) break;
                sdata.pop();
                pNextPop++;
            }

            if (sdata.empty() && pNextPop == popped.size())
                ans = true;
        }
        return ans;
    }
};
// @lc code=end

