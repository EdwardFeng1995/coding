/*
 * @lc app=leetcode.cn id=179 lang=cpp
 *
 * [179] 最大数
 */

// @lc code=start
class Solution {
public:
    static bool cmp(const int& x, const int& y) {
        string s1 = to_string(x);
        string s2 = to_string(y);
        return (s1+s2) > (s2+s1);
    }
    string largestNumber(vector<int>& nums) {
        if (all_of(nums.begin(), nums.end(), [](int x) { return x == 0; })) {
            return string("0");
        }
        sort(nums.begin(), nums.end(), cmp);
        string ans;
        for (auto &i:nums) {
            ans += to_string(i);
        }
        return ans;
    }
};
// @lc code=end

