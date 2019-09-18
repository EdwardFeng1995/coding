/*
 * @lc app=leetcode.cn id=47 lang=cpp
 *
 * [47] 全排列 II
 * 思路：比46多一个去重的步骤，这个去重思路用过很多次了，还有40.组合总和ii
 * nums排序，对于同一层，nums[i] == nums[i-1]，那么前面生成的结果中已经包含了接下来要生成的结果
 */

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int> &nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<int> temp;
        vector<vector<int>> res;
        vector<bool> visited(n, false);
        DFS(nums, temp, res, 0, visited);
        return res;
    }

    void DFS(vector<int> &nums, vector<int> &temp, vector<vector<int>> &res, int cursize, vector<bool> &visited) {
        if (cursize == nums.size()) {
            res.push_back(temp);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (!visited[i]) {
                if (i > 0 && nums[i] == nums[i - 1] && !visited[i - 1])
                    continue;
                temp.push_back(nums[i]);
                visited[i] = true;
                DFS(nums, temp, res, cursize + 1, visited);

                temp.pop_back();
                visited[i] = false;
            }
        }
    }

};


//   垃圾的set去重，我就是垃圾
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> temp;
        set<vector<int>> re_set;
        vector<bool> flag(nums.size(), false);
        sort(nums.begin(), nums.end());
        generate(0, flag, nums, temp, re_set, result);
        return result;
    }
private:
    void generate(int pos,
                  vector<bool>& flag,
                  vector<int>& nums,
                  vector<int>& temp,
                  set<vector<int>>& re_set,
                  vector<vector<int>>& result) {
        if (pos == nums.size()) {
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (!flag[i]) {
                flag[i] = true;
                temp.push_back(nums[i]);
                if (temp.size() == nums.size() && re_set.find(temp) == re_set.end()) {
                    result.push_back(temp);
                    re_set.insert(temp);
                }
                generate(pos+1, flag, nums, temp, re_set, result);
                temp.pop_back();
                flag[i] = false;
            }
        }
    }
};

