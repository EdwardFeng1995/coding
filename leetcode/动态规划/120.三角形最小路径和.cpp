/*
 * @lc app=leetcode.cn id=120 lang=cpp
 *
 * [120] 三角形最小路径和
 */

// @lc code=start
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        if (triangle.size() == 1) {
            return triangle[0][0];
        }
        vector<vector<int>> dp;
        for (int i = 0; i < triangle.size(); i++) {
            dp.push_back(vector<int>(i+1,0));
        }
        /* 从上往下
        dp[0][0] = triangle[0][0];
        dp[1][0] = dp[0][0] + triangle[1][0];
        dp[1][1] = dp[0][0] + triangle[1][1];
        for (int i = 2; i < dp.size(); i++) {
            for (int j = 0; j < dp[i].size(); j++) {
                if (j == 0) {
                    dp[i][j] = dp[i-1][j] + triangle[i][j];
                }
                else if (j == dp[i].size()-1) {
                    dp[i][j] = dp[i-1][j-1] + triangle[i][j];
                }
                else {
                    dp[i][j] = min(dp[i-1][j-1], dp[i-1][j]) + triangle[i][j];
                }  
            }
        }
        sort(dp[dp.size()-1].begin(), dp[dp.size()-1].end());
        return dp[dp.size()-1][0];
        */
        // 从下往上
        for (int i = 0; i < dp.size(); i++) {
            dp[dp.size()-1][i] = triangle[dp.size()-1][i];
        }
        for (int i= dp.size() - 2; i >= 0; i--) {
            for (int j = 0; j < dp[i].size(); j++) {
                dp[i][j] = min(dp[i+1][j], dp[i+1][j+1]) + triangle[i][j];
            }
        }
        return dp[0][0];
    }
};
// @lc code=end

