/*
 * @lc app=leetcode.cn id=322 lang=cpp
 *
 * [322] 零钱兑换
 * 一个经典的动态规划问题
 * 状态转移方程
 * dp[i] = 0,   n = 0;
 *         1 + min{dp[i-cj] | j∈[1,k]}   i >= cj
 */

// @lc code=start
//

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp;
        for (int i = 0; i <= amount; i++) {
            dp.push_back(-1);
        }
        dp[0] = 0;
        for (int i = 1; i <= amount; i++) {
            for (int j = 0; j < coins.size(); j++) {
                if (i - coins[j] >= 0 && dp[i-coins[j]] != -1) {
                    if (dp[i] == -1 || dp[i] > dp[i - coins[j]] + 1 )
                        dp[i] = dp[i - coins[j]] + 1;
                }
            }
        }
        return dp[amount];
    }
};

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, amount + 1);
        dp[0] = 0;
        for (int i = 1; i <= amount; i++) {
            for (int coin : coins)
                if (coin <= i)
                    dp[i] = min(dp[i], dp[i - coin] + 1);
        }
        return dp[amount] > amount ? -1 : dp[amount];
    }
};
// @lc code=end

