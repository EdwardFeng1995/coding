/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子序和
 * dp[i] 代表第i个数字结尾的最大子段和
 * 状态转移方程：
 * 如果第i-1个数字结尾的最大子段和>0，则dp[i] = dp[i-1] + nums[i]
 * 如果第i-1个数字结尾的最大字段和<0，则dp[i] = nums[i]
 * dp[i] = max(dp[i-1]+nums[i], nums[i])
 */

// @lc code=start
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int> dp(nums.size(),0);
        dp[0] = nums[0];
        int max_res = dp[0];
        for (int i = 1; i < nums.size(); i++) {
            dp[i] = max(dp[i-1]+nums[i], nums[i]);
            if (dp[i] > max_res) {
                max_res = dp[i];
            }
        }
        return max_res;
    }
};
// @lc code=end

