/*
 * @lc app=leetcode.cn id=45 lang=cpp
 *
 * [45] 跳跃游戏 II
 * 思路：贪心，在无法到达更远的地方时，在这之前应该跳到一个可以到达更远位置的位置
 */
class Solution {
public:
    int jump(vector<int>& nums) {
        if (nums.size() < 2) {
            return 0;
        }
        int current_max_index = nums[0];   // 当前可达到的最远位置
        int pre_max_max_index = nums[0];   // 遍历各个位置过程中，可达到的最远位置
        int jump_min = 1;
        for (int i = 1; i < nums.size(); i++) {  
            // 若无法再向前移动了，才进行跳跃
            // 如果前面不跳一下，就到不了位置i，跳一下，跳到能到达更远位置的位置
            if (i > current_max_index) {
                jump_min++;
                current_max_index = pre_max_max_index;  // 更新能当前可达到的最远位置
            }
            pre_max_max_index = max(pre_max_max_index, nums[i] + i);
        }
        return jump_min;
    }

};

