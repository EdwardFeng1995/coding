/*
 * @lc app=leetcode.cn id=64 lang=cpp
 *
 * [64] 最小路径和
 */

// @lc code=start
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        vector<vector<int>> dp;
        for (int i = 0; i < grid.size(); i++) {
            dp.push_back(vector<int>(grid[i].size(),0));
        }
        dp[0][0] = grid[0][0];
        for (int i = 0; i < dp.size(); i++) {
            for (int j = 0; j < dp[i].size(); j++) {
                if (i == 0 && j == 0) {
                    continue;
                }
                if (i - 1 < 0) {
                    dp[i][j] = dp[i][j-1] + grid[i][j];
                } else if (j - 1 < 0) {
                    dp[i][j] = dp[i-1][j] + grid[i][j];
                } else {
                    dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + grid[i][j];
                }
            }
        }
        return dp.back().back();
    }
};
// @lc code=end

