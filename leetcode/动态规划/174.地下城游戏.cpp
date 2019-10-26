/*
 * @lc app=leetcode.cn id=174 lang=cpp
 *
 * [174] 地下城游戏
 */

// @lc code=start
class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        if (dungeon.size() == 0) {
            return 0;
        }
        vector<vector<int> > dp(dungeon.size(), vector<int>(dungeon[0].size(), 0));
        int row = dungeon.size();
        int col = dungeon[0].size();
        dp[row-1][col-1] = max(1, 1 - dungeon[row-1][col-1]);
        for (int i = col - 2; i >= 0; i--) {
            dp[row-1][i] = max(1, dp[row-1][i+1] - dungeon[row-1][i]);
        }
        for (int i = row - 2; i >= 0; i--) {
            dp[i][col-1] = max(1, dp[i+1][col-1] - dungeon[i][col-1]);
        }
        for (int i = row - 2; i >= 0; i--) {
            for (int j = col -2; j >= 0; j--) {
                dp[i][j] = max(1, min(dp[i+1][j], dp[i][j+1]) - dungeon[i][j]);
            }
        }
        return dp[0][0];
    }
};
// @lc code=end

