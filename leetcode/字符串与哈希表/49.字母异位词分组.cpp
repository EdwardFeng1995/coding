/*
 * @lc app=leetcode.cn id=49 lang=cpp
 *
 * [49] 字母异位词分组
 */

// @lc code=start
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, vector<string>> anagram;
        vector<vector<string>> res;
        for (int i = 0; i < strs.size(); i++) {
            string str = strs[i];
            sort(str.begin(), str.end());
            if (anagram.find(str) == anagram.end()) {
                vector<string> item;
                anagram[str] = item;
            }
            anagram[str].push_back(strs[i]);
        }
        for (auto i : anagram) {
            res.push_back(i.second);
        }
        return res;
    }
};
// @lc code=end

