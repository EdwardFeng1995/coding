// 题目：连续子数组的最大和
// 输入一个整型数组，数组里有正数也有负数。
// 数组中的一个或连续多个整数组成一个子数组。
// 求所有子数组的和的最大值。要求时间复杂度O(n)


// 思路1：动态规划，dp[i]表示第i个数字结尾的子数组的最大和
// dp[i] = max(dp[i-1]+array[i], array[i]);
class Solution {
public:
    int FindGreatestSumOfSubArray(vector<int> array) {
        if (array.size() <= 0) return 0;
        vector<int> dp(array.size(), 0);
        dp[0] = array[0];
        int max_res = dp[0];
        for (int i = 1; i < dp.size(); i++) {
            dp[i] = max(dp[i-1]+array[i], array[i]);
            if (dp[i] > max_res) {
                max_res = dp[i];
            }
        }
        return max_res;
    }
};

// 思路2：按规律
class Solution {
public:
    int FindGreatestSumOfSubArray(vector<int> array) {
        if (array.size() <= 0) return 0;
        int sum = array[0];
        int max_res = array[0];
        for (int i = 1; i < array.size(); i++) {
            if (sum <= 0) {
                sum = array[i];
            } else {
                sum += array[i];
            }
            if (max_res < sum) {
                max_res = sum;
            }
        }
        return max_res;
    }
};
