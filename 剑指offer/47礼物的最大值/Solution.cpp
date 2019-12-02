// 题目：礼物的最大值
// 题目：在一个m×n的棋盘的每一格都放有一个礼物，每个礼物都有一定的价值
// （价值大于0）。你可以从棋盘的左上角开始拿格子里的礼物，并每次向左或
// 者向下移动一格直到到达棋盘的右下角。给定一个棋盘及其上面的礼物，请计
// 算你最多能拿到多少价值的礼物？


// 思路：典型动态规划
// dp[i][j] = max(dp[i-1][j], dp[i][j-1]) + gift[i][j]

class Solution {
public:
    int getMaxValue_solution1(const int* values, int rows, int cols)
    {
        if(values == nullptr || rows <= 0 || cols <= 0)
            return 0;
        vector<vector<int>> dp;
        for (int i = 0; i < rows; i++) {
            dp.push_back(vector<int>(cols, 0));
        }
        dp[0][0] = values[0];
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (i == 0 && j == 0) continue;
                if (i-1 < 0) {
                    dp[i][j] = dp[i][j-1] + values[i*cols + j];
                } else if (j-1 < 0) {
                    dp[i][j] = dp[i-1][j] + values[i*cols + j];
                } else {
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]) + values[i*cols + j];
                }
            }
        }
        return dp.back().back();
    }
};
