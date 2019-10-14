/*
 * @lc app=leetcode.cn id=1052 lang=cpp
 *
 * [1052] 爱生气的书店老板
 */

// @lc code=start

// 思路1:
// 滑动窗口，加窗尾减窗头，时间复杂度O(n)
// 先统计出所有0对应的customer数sum_of_0
// 每次统计窗口总数 + sum_of_0 - 窗口0对应的customer数
class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int X) {
        int sum_of_0 = 0;  // 统计所有0对应的customer数
        int max_sum = 0;   // 保存结果
        int sum_win1 = 0;  // 统计窗口总和
        int sum_win2 = 0;  // 窗口中0对应的customer综合
        for (int i = 0; i < customers.size(); i++) {
            if (grumpy[i] == 0) {
                sum_of_0 += customers[i];
            }
        }
        // 第一个窗口
        for (int i = 0; i < X; i++) {
            sum_win1 += customers[i];
            if (grumpy[i] == 0) {
                sum_win2 += customers[i];
            }
        }
        max_sum = sum_win1 + sum_of_0 - sum_win2;
        for (int i = X; i < customers.size(); i++) {
            // 窗口移动
            sum_win1 = sum_win1 + customers[i] - customers[i-X];
            if (grumpy[i-X] == 0) {
                sum_win2 -= customers[i-X];
            }
            if (grumpy[i] == 0) {
                sum_win2 += customers[i];
            }
            if (sum_win1 + sum_of_0 - sum_win2 > max_sum) {
                max_sum = sum_win1 + sum_of_0 - sum_win2;
            }
        }
        return max_sum;
    }
};
// @lc code=end


// 思路2：
// 时间复杂度O(n)
class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int X) {
        int sum_of_0 = 0;
        int max_sum = 0;
        for (int i = 0; i < customers.size(); i++) {
            if (grumpy[i] == 0) {
                sum_of_0 += customers[i];
            }
        }
        //cout << sum_of_0 << endl;
        for (int i = 0; i <= customers.size() - X; i++) {
            int sum1 = 0;
            int sum2 = 0;
            for (int j = i; j < i+X; j++) {
                sum1 += customers[j];
                if (grumpy[j] == 0) {
                    sum2 += customers[j];
                }
            }
            //cout << sum1 << " " << sum2 << endl;
            sum1 = sum1 + sum_of_0 - sum2;
            if (sum1 > max_sum) {
                max_sum = sum1;
            }
        }
        return max_sum;
    }
};
