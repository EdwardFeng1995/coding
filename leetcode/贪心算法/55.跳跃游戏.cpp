/*
 * @lc app=leetcode.cn id=55 lang=cpp
 *
 * [55] 跳跃游戏
 * 思路：贪心算法，记录能跳到点的最大值，如果当前点超出最大值，返回false.
 */
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int k = 0;
	    for (int i = 0; i < nums.size(); i++)
	    {
		    if (i > k) return false;
		    k = max(k, i + nums[i]);
	    }
	    return true;
    }
};


class Solution {
public:
    bool canJump(vector<int>& nums) {
        for (int i = 0, j = 0; i <= j; i++) {
            j = max(i + nums[i], j);
            if (j >= nums.size() - 1) {
                return true;
            }
        }
        return false;
    }
};
