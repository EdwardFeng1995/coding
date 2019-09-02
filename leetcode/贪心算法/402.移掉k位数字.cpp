/*
 * @lc app=leetcode.cn id=402 lang=cpp
 *
 * [402] 移掉K位数字
 * 思路：贪心，从高位向低位遍历，如果对应的数字大于下一位数字，则把该位数字去掉，得到的数字最小
 */
class Solution {
public:
    string removeKdigits(string num, int k) {
        std::vector<int> s;        // 拿vector当栈使用
        std::string result = "";   // 存储最终结果的字符串
        for (int i = 0; i < num.size(); i++) {
            int number = num[i] - '0';  // 将字符型的num转化为整数使用
            while (s.size() != 0 && number < s.back() && k >0) {  // 当栈不空，栈顶元素大于number，仍然可以删
                s.pop_back();   // 删除栈顶元素
                k--;  // 相当于已经删了一个数字，k--
            }
            if (number != 0 || s.size() != 0) {
                s.push_back(number);
            }
        }
        while (s.size() != 0 && k > 0) {  // 如果栈不空，且仍然可以删除
            s.pop_back();
            k--;
        }
        for (int i = 0; i < s.size(); i++) {  // 将栈中的元素从头遍历，存储至result
            result.append(1, '0'+s[i]);
        }
        if (result == "") {
            result = "0";   // 如果result为空，result即为0
        }
        return result;
    }
};

