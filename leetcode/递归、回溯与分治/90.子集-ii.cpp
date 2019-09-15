/*
 * @lc app=leetcode.cn id=90 lang=cpp
 *
 * [90] 子集 II
 * 思路:递归加回溯，用set去重
 */
#include <algorithm>
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> item;
        set<vector<int>> res_set;
        sort(nums.begin(), nums.end());
        result.push_back(item);
        generate(0, nums, result, item, res_set);
        return result;
    }
private:
    void generate(int pos, vector<int>&nums, 
                  vector<vector<int>>& result,
                  vector<int>& item,
                  set<vector<int>>& res_set) {
        if (pos >= nums.size()) {
            return;
        }
        for (int i = pos; i < nums.size(); i++) {
            item.push_back(nums[i]);
            if (res_set.find(item) == res_set.end()) {
                result.push_back(item);
                res_set.insert(item);
            }
            generate(i+1, nums, result, item, res_set);
            item.pop_back();
        }
    }
};

