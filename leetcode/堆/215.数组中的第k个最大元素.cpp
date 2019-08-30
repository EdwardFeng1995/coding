/*
 * @lc app=leetcode.cn id=215 lang=cpp
 *
 * [215] 数组中的第K个最大元素
 * 思路：创建一个K大小的最小堆，保存数组前K大的元素
 *       遍历数组元素，如果最小堆还没满，就push
 *       如果堆满了，如果元素比对顶大，则更换对顶
 *       返回对顶就是第K大元素
 */
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        std::priority_queue<int, std::vector<int>, std::greater<int> > Q;
        for (int i = 0; i < nums.size(); i++) {
            if (Q.size() < k) {
                Q.push(nums[i]);
            } else if (nums[i] > Q.top()) {
                Q.pop();
                Q.push(nums[i]);
            }
        }
        return Q.top();
    }
};

