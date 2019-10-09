/*
 * @lc app=leetcode.cn id=35 lang=cpp
 *
 * [35] 搜索插入位置
 */

// @lc code=start
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int begin = 0;
        int end = nums.size() - 1;
        int mid = (end + begin)/2;
        int re;
        while (begin <= end) {
            if (target == nums[mid]) {
                re = mid;
                break;
            } else if (target < nums[mid]) {
                end = mid - 1;
            } else {
                begin = mid + 1;
            }
            if (begin > end) {
                re =  end + 1;
            }
            mid = (end + begin)/2;
        }
        return re;
    }
};
// @lc code=end

