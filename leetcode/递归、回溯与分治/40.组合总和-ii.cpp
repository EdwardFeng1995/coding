/*
 * @lc app=leetcode.cn id=40 lang=cpp
 *
 * [40] 组合总和 II
 * 思路：递归+回溯套路，本题与39题，不允许重复集合，且每个数只能用一次
 *       所以递归从i+1开始，加一个去重的步骤，可以使用set去重，但是set底层实现复杂
 *       在遍历的时候，如果candidates[i] == candidates[i-1] 则跳过，就可以去重
 */

class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> ans;
        recurs(candidates, ans, 0, target);
        return res;
    }
    void recurs(vector<int>& candidates, vector<int>& ans, int pos, int target) {
        if (target==0) {
            res.push_back(ans);
            return;
        }
        for (int i = pos; i < candidates.size(); ++i) {
            if (target - candidates[i] >= 0) {
                if (i!=pos && candidates[i]==candidates[i-1]) // 去掉重复，如果当前数与前一个数相同，则跳过
                    continue;
                ans.push_back(candidates[i]);
                recurs(candidates, ans, i+1, target-candidates[i]);
                ans.pop_back();
            } else { // 剪枝
                break;
            }
        }
    }
};


class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        set<vector<int>> re_set;
        vector<int> temp;
        sort(candidates.begin(), candidates.end());
        generate(0, target, candidates, temp, result, re_set);
        return result;
    }
private:
    void generate(int pos, int target,
                  vector<int>& candidates, 
                  vector<int>& temp,
                  vector<vector<int>>& result,
                  set<vector<int>>& re_set
                  ) {
        if (pos >= candidates.size() || target < 0) {
            return;
        }
        for (int i = pos; i < candidates.size() && (target - candidates[i]) >= 0; i++) {
            temp.push_back(candidates[i]);
            target = target - candidates[i];
            if (re_set.find(temp) == re_set.end() && target == 0) {
                result.push_back(temp);
                re_set.insert(temp);
            }
            generate(i+1, target, candidates, temp, result, re_set);
            // 回溯
            target += candidates[i];
            temp.pop_back();
        }
    }
};

