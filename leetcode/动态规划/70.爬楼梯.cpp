/*
 * @lc app=leetcode.cn id=70 lang=cpp
 *
 * [70] 爬楼梯
 * 实质就是个斐波那契数列，fn = fn_1 + fn_2
 * 可以转为动态规划
 */

// @lc code=start

// 斐波那契写法
class Solution {
public:
    int climbStairs(int n) {
        if (n == 1) {
            return 1;
        }
        if (n == 2) {
            return 2;
        }
        int sum = 0, fn_1 = 2, fn_2 = 1;
        for (int i = 3; i <= n; i++) {
            sum = fn_1 + fn_2;
            int temp = fn_1;
            fn_1 = sum;
            fn_2 = temp;
        }
        return sum;
    }
};

// 动态规划写法
class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp(n+3, 0);
        dp[1] = 1;
        dp[2] = 2;
        for (int i = 3; i <= n; i++) {
            dp[i] = dp[i-1] + dp[i-2]; 
        }
        return dp[n];
    }
};
// @lc code=end

