/*
 * @lc app=leetcode.cn id=39 lang=cpp
 *
 * [39] 组合总和
 * 思路：递归+回溯套路，本题允许数字使用很多次，所以递归从i开始，不是i+1
 */
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> temp;
        sort(candidates.begin(), candidates.end());
        generate(0, candidates, result, temp, target);
        return result;
    }
private:
    void generate(int pos,
                  vector<int>& candidates,
                  vector<vector<int>>& result,
                  vector<int>& temp,
                  int target
                 ) {
        if (target == 0) {
            result.push_back(temp);
            return;
        }
        for (int i = pos; i < candidates.size(); i++) {
            if (target - candidates[i] >= 0) {
                temp.push_back(candidates[i]);
                generate(i, candidates, result, temp, target - candidates[i]);
                temp.pop_back();
            } else {
                break;
            }
        }
    }
};

