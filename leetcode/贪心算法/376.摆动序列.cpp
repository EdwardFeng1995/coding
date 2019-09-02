/*
 * @lc app=leetcode.cn id=376 lang=cpp
 *
 * [376] 摆动序列
 * 思路：贪心，找上升的最大和下降的最小，也就是找拐点
 */
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if (nums.size() < 2) {   // 原序列个数小于2时直接为摇摆序列
            return nums.size();
        }
        int prediff = nums[1] - nums[0];   // 指示当前序列是上升还是下降
        int count = prediff != 0 ? 2 : 1;
        for (int i = 2; i < nums.size(); i++) {
            int diff = nums[i] - nums[i-1];
            // 统计交替点，上升转为下降或者下降转为上升
            if ((prediff >= 0 && diff < 0) || (prediff <= 0 && diff > 0)) {
                count++;
                prediff = diff;
            }
        }
        return count;
    }
};

// 以下为状态机的思路，代码有些繁琐
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if (nums.size() < 2) {   // 原序列个数小鱼2时直接为摇摆序列
            return nums.size();
        }
        static const int BEGIN = 0;
        static const int UP = 1;     // 扫描序列时的三种状态
        static const int DOWN = 2;
        int STATE = BEGIN;
        int max_length = 1;          // 摇摆序列最大长度至少为1
        for (int i = 1; i < nums.size(); i++) {
            switch(STATE) {
            case BEGIN:
                if (nums[i] > nums[i-1]) {
                    STATE = UP;
                    max_length++;
                } else if (nums[i] < nums[i-1]) {
                    STATE = DOWN;
                    max_length++;
                }
                break;
            case UP:
                if (nums[i] < nums[i-1]) {
                    STATE = DOWN;
                    max_length++;
                }
                break;
            case DOWN:
                if (nums[i] > nums[i-1]) {
                    STATE = UP;
                    max_length++;
                }
                break;
            }
        }
        return max_length;
    }
};
