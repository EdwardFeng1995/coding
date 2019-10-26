/*
 * @lc app=leetcode.cn id=300 lang=cpp
 *
 * [300] 最长上升子序列
 */

// @lc code=start
// 思路1：动态规划，dp[i]代表以第i个元素结尾的最长上升子序列的长度
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        }
        // dp[i]代表以第i个元素结尾的最长上升子序列的长度
        vector<int> dp(nums.size(), 0);
        dp[0] = 1;
        int LIS = 1;
        for (int i = 1; i < dp.size(); i++) {
            dp[i] = 1;
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j] && dp[i] < dp[j] + 1) {
                    dp[i] = dp[j] + 1;
                }
            }
            if (LIS < dp[i]) {
                LIS = dp[i];
            }
        }
        return LIS;
    }
};

// 思路2：设置一个栈，然后遍历，若nums[i] > 栈顶元素，将nums[i] push 进栈中
// 否则，从栈底遍历至栈顶，若栈中元素大于等于nums[i]，使用nums[i]替换，并跳出循环。
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        }
        vector<int> stack;
        stack.push_back(nums[0]);
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > stack.back()) {
                stack.push_back(nums[i]);
            } else {
                for (int j = 0; j < stack.size(); j++) {
                    if (nums[i] <= stack[j]) {
                        stack[j] = nums[i];
                        break;
                    }
                }
            }
        }
        return stack.size();
    }
};

// 思路2优化至O(nlogn)，用二分查找
int binary_search(vector<int> nums, int target) {
    int index = -1;
    int begin = 0;
    int end = nums.size() - 1;
    while (index == -1) {
        int mid = (begin + end) / 2;
        if (target == nums[mid]) {
            index = mid;
        } else if (target < nums[mid]) {
            if (mid == 0 || target > nums[mid-1]) {
                index = mid;
            }
            end = mid -1;
        } else if (target > nums[mid]) {
            if (mid == nums.size() -1 || target < nums[mid+1]) {
                index = mid + 1;
            }
            begin = mid + 1;
        }
    }
    return index;
}
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        }
        vector<int> stack;
        stack.push_back(nums[0]);
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > stack.back()) {
                stack.push_back(nums[i]);
            } else {
                int pos = binary_search(stack, nums[i]);
                stack[pos] = nums[i];
            }
        }
        return stack.size();
    }
};
// @lc code=end

