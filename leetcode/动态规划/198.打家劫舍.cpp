/*
 * @lc app=leetcode.cn id=198 lang=cpp
 *
 * [198] 打家劫舍
 * dp[i]为第i个房间的最优解
 * 确定状态转移方程：
 * a.选择第i个房间：第i个房间+前i-2个房间的最优解
 * b.不选择第i个房间：前i-1个房间的最优解
 * dp[i] = max(dp[i-1], dp[i-2] + nums[i]) (i>=3)
 */

// @lc code=start
class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        }
        if (nums.size() == 1) {
            return nums[0];
        }
        vector<int> dp(nums.size(), 0);
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        for (int i = 2; i < nums.size(); i++) {
            dp[i] = max(dp[i-1], dp[i-2]+nums[i]);
        }
        return dp[nums.size()-1];
    }
};
// @lc code=end

