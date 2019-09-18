/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
 */
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> temp;
        vector<bool> flag(nums.size(), false);
        generate(0, flag, nums, temp, result);
        return result;
    }
private:
    void generate(int pos,
                  vector<bool>& flag,
                  vector<int>& nums,
                  vector<int>& temp,
                  vector<vector<int>>& result) {
        if (pos == nums.size()) {
            result.push_back(temp);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (!flag[i]) {
                flag[i] = true;
                temp.push_back(nums[i]);
                generate(pos+1, flag, nums, temp, result);
                temp.pop_back();
                flag[i] = false;
            }
        }
    }
};

